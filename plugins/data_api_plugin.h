/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：data_api_plugin.h
*   Create Time：2013.02.05
*   Description：
*
================================================================*/

#ifndef ANTIFRAUD_DATA_API_PLUGIN_H_
#define ANTIFRAUD_DATA_API_PLUGIN_H_

#include "iplugin.h"

#include "result_info.pb.h"
#include "behavior_data.pb.h"

namespace antifraud {

class DataApiPlugin : public IPlugin {
public:
  DataApiPlugin();
  virtual ~DataApiPlugin();

  virtual int Init(const std::string& conf_file);

  virtual int Process(const BehaviorData& data, ResultInfo* result); 
};

extern "C" IPlugin* CreateDataApiPlugin();
extern "C" void DeleteDataApiPlugin(IPlugin* p);  

}  // end namespace 

#endif  // ANTIFRAUD_DATA_API_PLUGIN_H_
