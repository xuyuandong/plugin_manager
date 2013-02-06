/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：plugin_holder.cc
*   Create Time：2013.02.05
*   Description：
*
================================================================*/
#include "plugin_holder.h"
#include "plugin_factory.h"

using namespace std;

namespace antifraud {

PluginHolder::~PluginHolder() {
  PluginFactory::DelPlugin(name_, ptr_);
}

void PluginHolder::reset(const string& name) {
  if (ptr_ != NULL) {
    PluginFactory::DelPlugin(name_, ptr_);
  }
  name_ = name;
  ptr_ = PluginFactory::GetPlugin(name);
}

}  // end namespace
