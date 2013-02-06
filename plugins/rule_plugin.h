/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：rule_plugin.h
*   Create Time：2013.02.04
*   Description：
*
================================================================*/

#ifndef ANTIFRAUD_RULE_PLUGIN_H_
#define ANTIFRAUD_RULE_PLUGIN_H_

#include "iplugin.h"

#include "result_info.pb.h"
#include "behavior_data.pb.h"

namespace antifraud {

class RulePlugin : public IPlugin {
public:
  RulePlugin();
  virtual ~RulePlugin();

  virtual int Init(const std::string& conf_file);

  virtual int Process(const BehaviorData& data, ResultInfo* result); 

};

extern "C" IPlugin* CreateRulePlugin();
extern "C" void DeleteRulePlugin(IPlugin* p);  

}  // end namespace

#endif  // ANTIFRAUD_RULE_PLUGIN_H_
