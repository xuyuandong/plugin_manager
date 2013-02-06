/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：rule_plugin.cc
*   Create Time：2013.02.04
*   Description：
*
================================================================*/

#include "rule_plugin.h"

#include "base/logging.h"

using namespace std;

namespace antifraud {

RulePlugin::RulePlugin() {
  VLOG(1) << "construct rule plugin";
}

RulePlugin::~RulePlugin() {
  VLOG(1) << "destroy rule plugin";
}

int RulePlugin::Init(const string& conf_file) {
  VLOG(1) << "init config file";
  return 0;
}

int RulePlugin::Process(const BehaviorData& data, ResultInfo* result) {
  VLOG(1) << "process rules";
  return 0;
}

IPlugin* CreateRulePlugin() {
  VLOG(1) << "create rule plugin";
  return new (nothrow) RulePlugin();
}

void DeleteRulePlugin(IPlugin* p) {
  VLOG(1) << "delete rule plugin";
  delete p;
  p = NULL;
}


}  // end namespace 
