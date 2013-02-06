/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：data_api_plugin.cc
*   Create Time：2013.02.04
*   Description：
*
================================================================*/

#include "data_api_plugin.h"

#include "base/logging.h"

using namespace std;

namespace antifraud {

DataApiPlugin::DataApiPlugin() {
  VLOG(1) << "construct data api plugin";
}

DataApiPlugin::~DataApiPlugin() {
  VLOG(1) << "destroy data api plugin";
}

int DataApiPlugin::Init(const string& conf_file) {
  VLOG(1) << "init config file";
  return 0;
}

int DataApiPlugin::Process(const BehaviorData& data, ResultInfo* result) {
  VLOG(1) << "process rules";
  return 0;
}

IPlugin* CreateDataApiPlugin() {
  VLOG(1) << "create data api plugin";
  return new (nothrow) DataApiPlugin();
}

void DeleteDataApiPlugin(IPlugin* p) {
  VLOG(1) << "delete data api plugin";
  delete p;
  p = NULL;
}


}  // end namespace 
