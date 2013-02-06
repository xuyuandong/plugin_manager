/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：iplugin.h
*   Create Time：2013.02.04
*   Description：
*
================================================================*/

#ifndef ANTIFRAUD_IPLUGIN_H_
#define ANTIFRAUD_IPLUGIN_H_

#include <string>

#include "result_info.pb.h"
#include "behavior_data.pb.h"

namespace antifraud {

class IPlugin {
public:
  virtual ~IPlugin() {};

  virtual int Init(const std::string& conf_file) = 0;

  virtual int Process(const BehaviorData& data, ResultInfo* result) = 0; 
};

}  // end namespace

#endif  // ANTIFRAUD_IPLUGIN_H_
