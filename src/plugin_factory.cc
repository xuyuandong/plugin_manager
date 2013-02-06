/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：plugin_factory.cc
*   Create Time：2013.02.01
*   Description：
*
================================================================*/
#include "plugin_factory.h"

#include <dlfcn.h>
#include "base/file.h"
#include "base/logging.h"
#include "base/proto_util.h"
#include "plugin_conf.pb.h"

using namespace std;

namespace antifraud {

map<string, PluginObj> PluginFactory::plugin_map_;

void PluginFactory::Init(const string& conf_file) {
  string text;
  file::File::ReadFileToString(conf_file, &text);
  CHECK(!text.empty()) << "failed to read plugin config :" << conf_file; 
  
  PluginSet plugin_set;
  bool flag = base::proto_util::ParseFromASCII(text, &plugin_set);
  CHECK(flag) << "failed to parse plugin config file";

  for (int i = 0; i < plugin_set.plugins_size(); ++i) {
    const PluginInfo& pinfo = plugin_set.plugins(i);
    PluginObj pobj;
    CHECK(!LoadPlugin(pinfo, &pobj)) << "failed to load plugin";
    plugin_map_[pinfo.name()] = pobj;
  }
  LOG(INFO) << "finished init plugin factory";
}

IPlugin* PluginFactory::GetPlugin(const string& name) {
  if (plugin_map_.end() == plugin_map_.find(name)) {
    LOG(ERROR) << "failed to find plugin for " << name;
    return NULL;
  }
  const PluginObj& pobj = plugin_map_[name];
  if (NULL == pobj.cre_func_) {
    LOG(ERROR) << "uninitialized create function ptr for " << name;
    return NULL;
  }
  return (*pobj.cre_func_)();
}

void PluginFactory::DelPlugin(const std::string& name, IPlugin* ptr) {
  if (plugin_map_.end() == plugin_map_.find(name)) {
    LOG(ERROR) << "failed to find plugin for " << name;
    return;
  }
  const PluginObj& pobj = plugin_map_[name];
  if (NULL == pobj.del_func_) {
    LOG(ERROR) << "uninitialized delete function ptr for " << name;
    return;
  }
  return (*pobj.del_func_)(ptr);
}

int PluginFactory::LoadPlugin(const PluginInfo& pinfo, PluginObj* pobj) {
  const string& so_name = pinfo.name();
  
  const string& so_path = pinfo.path();
  void* so_handle = dlopen(so_path.c_str(), RTLD_LAZY);
  if (NULL == so_handle) {
    LOG(ERROR) << "failed to load plugin " << so_name
      << " at " << so_path << " :" << dlerror();
    return 1;
  }
  pobj->handle_ = so_handle;
  
  if (pinfo.has_create_symbol()) {
    CreateFunc* so_ptr = NULL;
    const string& so_symbol = pinfo.create_symbol();
    so_ptr = (CreateFunc*)dlsym(so_handle, so_symbol.c_str());
    if (NULL == so_ptr) {
      LOG(ERROR) << "dlsym error for symbol " << so_symbol
        << " :" << dlerror();
      return 1;
    }
    pobj->cre_func_ = so_ptr;
  }

  if (pinfo.has_delete_symbol()) {
    DeleteFunc* so_ptr = NULL;
    const string& so_symbol = pinfo.delete_symbol();
    so_ptr = (DeleteFunc*)dlsym(so_handle, so_symbol.c_str());
    if (NULL == so_ptr) {
      LOG(ERROR) << "dlsym error for symbol " << so_symbol
        << " :" << dlerror();
      return 1;
    }
    pobj->del_func_ = so_ptr;
  }

  LOG(INFO) << "load plugin for " << so_name << " successfully";
  return 0;
}

void PluginFactory::UnloadPlugin(const string& name) {
  if (plugin_map_.end() == plugin_map_.find(name)) {
    LOG(ERROR) << "failed to find plugin " << name;
    return;
  }

  const PluginObj& pobj = plugin_map_[name];
  if (0 != dlclose(pobj.handle_)) {
    LOG(ERROR) << "failed to unload plugin " << name
      << " :" << dlerror();
  }
  plugin_map_.erase(name);
}

}  // end namespace
