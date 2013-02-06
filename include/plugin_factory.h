/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：plugin_factory.h
*   Create Time：2013.02.01
*   Description：
*
================================================================*/

#ifndef ANTIFRAUD_PLUGIN_FACTORY_H_
#define ANTIFRAUD_PLUGIN_FACTORY_H_

#include <map>
#include <string>
#include "iplugin.h"

namespace antifraud {

class PluginInfo;

typedef IPlugin* CreateFunc();
typedef void DeleteFunc(IPlugin*);

class PluginObj {
 public:
  PluginObj() : handle_(NULL) {}
  void* handle_;
  CreateFunc* cre_func_;
  DeleteFunc* del_func_;
};

class PluginFactory {
 public:
  static void Init(const std::string& conf_file);
  
  static IPlugin* GetPlugin(const std::string& name);
  static void DelPlugin(const std::string& name, IPlugin* ptr);

 private:
  static int LoadPlugin(const PluginInfo& pinfo, PluginObj* pobj);
  static void UnloadPlugin(const std::string& name);

  static std::map<std::string, PluginObj> plugin_map_;
};

}  // end namespace

#endif  // ANTIFRAUD_PLUGIN_FACTORY_H_
