/*===============================================================
*   Copyright (C) 2013 Sina Inc All rights reserved.
*   
*   Author：xuyuandong
*   File Name：plugin_holder.h
*   Create Time：2013.02.05
*   Description：
*
================================================================*/

#ifndef PLUGIN_HOLDER_H_
#define PLUGIN_HOLDER_H_

#include <string>
#include "base/port.h"
#include "plugin_factory.h"

namespace antifraud {

template <typename T>
class PluginPtr {
public:
  explicit PluginPtr() : ptr_(NULL) {}
  ~PluginPtr() {
    PluginFactory<T>::DelPlugin(name_, ptr_);
    ptr_ = NULL;
  }

  const std::string& name() {
    return name_;
  }

  void reset(const std::string& name) {
    if (ptr_ != NULL) {
      PluginFactory<T>::DelPlugin(name_, ptr_);
    }
    name_ = name;
    ptr_ = PluginFactory<T>::GetPlugin(name);
  }

  T* get() const { return ptr_; }

  // Accessors to get the owned object.
  T& operator*() const {
    assert(ptr_ != NULL);
    return *ptr_;
  }
  T* operator->() const {
    assert(ptr_ != NULL);
    return ptr_;
  }
 
  // Comparison operators.
  bool operator==(T* p) const { return ptr_ == p; }
  bool operator!=(T* p) const { return ptr_ != p; }

  void swap(PluginPtr& other) {
    T* tmp = ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = tmp;
  }

  T* release() WARN_UNUSED_RESULT {
    T* p = ptr_;
    ptr_ = NULL;
    return p;
  }

private:
  T* ptr_;
  std::string name_;

  PluginPtr(const PluginPtr&);
  void operator=(const PluginPtr&);
};


}

#endif  // PLUGIN_HOLDER_H_
