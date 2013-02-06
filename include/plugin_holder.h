/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：plugin_holder.h
*   Create Time：2013.02.05
*   Description：
*
================================================================*/

#ifndef ANTIFRAUD_PLUGIN_HOLDER_H_
#define ANTIFRAUD_PLUGIN_HOLDER_H_

#include <string>
#include "iplugin.h"

namespace antifraud {

class PluginHolder {
public:
  explicit PluginHolder() : ptr_(NULL) {}
  ~PluginHolder();

  void reset(const std::string& name);

  // Accessors to get the owned object.
  IPlugin& operator*() const {
    assert(ptr_ != NULL);
    return *ptr_;
  }
  IPlugin* operator->() const {
    assert(ptr_ != NULL);
    return ptr_;
  }
 
  // Comparison operators.
  bool operator==(IPlugin* p) const { return ptr_ == p; }
  bool operator!=(IPlugin* p) const { return ptr_ != p; }

private:
  IPlugin* ptr_;
  std::string name_;

  PluginHolder(const PluginHolder&);
  void operator=(const PluginHolder&);
};

typedef PluginHolder PluginPtr;

}  // end namespace

#endif  // ANTIFRAUD_PLUGIN_HOLDER_H_
