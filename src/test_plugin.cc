/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：test_plugin_factory.cc
*   Create Time：2013.02.04
*   Description：
*
================================================================*/

#include "base/flags.h"
#include "base/logging.h"

#include "plugin_holder.h"
#include "plugin_factory.h"

using namespace antifraud;

DEFINE_string(conf_file, "plugins.conf", "config file for test");

int main(int argc, char* argv[]) {
  base::ParseCommandLineFlags(&argc, &argv, true);

  PluginFactory factory;
  factory.Init(FLAGS_conf_file);

  //IPlugin* ptr = (factory.GetPlugin("RulePlugin"));
  PluginPtr ptr;
  ptr.reset("RulePlugin");
  ptr->Init(FLAGS_conf_file);

  ResultInfo result;
  BehaviorData data;
  ptr->Process(data, &result);

  return 0;
}
