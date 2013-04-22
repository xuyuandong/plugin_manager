/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：plugin_factory.h
*   Create Time：2013.02.01
*   Description：
*
================================================================*/

#ifndef PLUGIN_FACTORY_H_
#define PLUGIN_FACTORY_H_

#include <map>
#include <vector>
#include <string>

#include <dlfcn.h>
#include "base/mutex.h"
#include "logging_wrapper.h"

namespace ad_processor {

struct PluginInfo {
  std::string name_;
  std::string path_;
  std::string create_symbol_;
  std::string delete_symbol_;
  std::string conf_path_;
};

template <typename T>
class PluginFactory {
 public:
   static int Init(const std::vector<PluginInfo>& info_vec) {
     static bool once_ = false;
     static base::Mutex mutex_;

     base::MutexLock lock(&mutex_);
     if (once_) return 0;

     for (size_t i = 0; i < info_vec.size(); ++i) {
       const PluginInfo& pinfo = info_vec[i];
       Log(Debug, "load plugin name : %s", pinfo.name_.c_str());
       ASSERT_RETURN(plugin_map_.find(pinfo.name_) == plugin_map_.end(), 
           "%s is loaded duplicated, please check", pinfo.name_.c_str());

       PluginObj pobj;
       ASSERT_RETURN(!LoadPlugin(pinfo, &pobj), "failed to load plugin");

       plugin_map_[pinfo.name_] = pobj;
     }

     Log(Notice, "finished init plugin factory");
     once_ = true;
     return 0;
   }
  
   static T* GetPlugin(const std::string& name) {
     CHECK_RETURN(NULL, plugin_map_.end() != plugin_map_.find(name), 
         "failed to find plugin for %s", name.c_str());

     const PluginObj& pobj = plugin_map_[name];
     CHECK_RETURN(NULL, NULL != pobj.cre_func_, 
         "uninitialized create function ptr for %s", name.c_str());

     T* ptr = (*pobj.cre_func_)();
     CHECK_RETURN(NULL, NULL != ptr, "failed to create ptr: %s", name.c_str());

     if (!pobj.conf_path_.empty() && 0 != ptr->Init(pobj.conf_path_)) {
       Log(Error, "failed to initialize plugin %s", name.c_str());
       DelPlugin(name, ptr);
       return NULL;
     }
     return ptr;
  };

   static void DelPlugin(const std::string& name, T* ptr) {
     if (plugin_map_.end() == plugin_map_.find(name)) {
       Log(Error, "failed to find plugin for %s", name.c_str());
       return;
     }
     const PluginObj& pobj = plugin_map_[name];
     if (NULL == pobj.del_func_) {
       Log(Error, "uninitialized delete function ptr for %s", name.c_str());
       return;
     }
     return (*pobj.del_func_)(ptr);
  };

 private:
  typedef T* CreateFunc();
  typedef void DeleteFunc(T*);
  struct PluginObj {
    PluginObj() : handle_(NULL) {}
    void* handle_;
    CreateFunc* cre_func_;
    DeleteFunc* del_func_;
    std::string conf_path_;
  };

  static int LoadPlugin(const PluginInfo& pinfo, PluginObj* pobj) {
    const std::string& so_name = pinfo.name_;

    const std::string& so_path = pinfo.path_;
    void* so_handle = dlopen(so_path.c_str(), RTLD_LAZY);
    if (NULL == so_handle) {
      Log(Error, "failed to load plugin %s at %s : %s", 
          so_name.c_str(), so_path.c_str(), dlerror());
      return 1;
    }
    pobj->handle_ = so_handle;

    if (!pinfo.create_symbol_.empty()) {
      CreateFunc* so_ptr = NULL;
      const std::string& so_symbol = pinfo.create_symbol_;
      so_ptr = (CreateFunc*)dlsym(so_handle, so_symbol.c_str());
      ASSERT_RETURN(NULL != so_ptr, 
          "dlsym error for symbol %s : %s", so_symbol.c_str(), dlerror());
      pobj->cre_func_ = so_ptr;
    }

    if (!pinfo.delete_symbol_.empty()) {
      DeleteFunc* so_ptr = NULL;
      const std::string& so_symbol = pinfo.delete_symbol_;
      so_ptr = (DeleteFunc*)dlsym(so_handle, so_symbol.c_str());
      ASSERT_RETURN(NULL != so_ptr, 
          "dlsym error for symbol %s : %s", so_symbol.c_str(), dlerror());
      pobj->del_func_ = so_ptr;
    }

    if (!pinfo.conf_path_.empty()) 
      pobj->conf_path_ = pinfo.conf_path_;

    Log(Notice, "load plugin for %s successfully", so_name.c_str());
    return 0;
  };
  
  static void UnloadPlugin(const std::string& name){
    if (plugin_map_.end() == plugin_map_.find(name)) {
      Log(Error, "failed to find plugin for %s", name.c_str());
      return;
    }

    const PluginObj& pobj = plugin_map_[name];
    if (0 != dlclose(pobj.handle_)) {
      Log(Error, "failed to unload plugin %s : %s", name.c_str(), dlerror());
    }
    plugin_map_.erase(name);
  };

  static std::map<std::string, PluginObj> plugin_map_;
};

template<typename T> std::map<std::string, struct PluginFactory<T>::PluginObj> PluginFactory<T>::plugin_map_;

}  // end namespace

#endif  // PLUGIN_FACTORY_H_
