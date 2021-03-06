// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "plugin_conf.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace antifraud {

namespace {

const ::google::protobuf::Descriptor* PluginInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PluginInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* PluginSet_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PluginSet_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_plugin_5fconf_2eproto() {
  protobuf_AddDesc_plugin_5fconf_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "plugin_conf.proto");
  GOOGLE_CHECK(file != NULL);
  PluginInfo_descriptor_ = file->message_type(0);
  static const int PluginInfo_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginInfo, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginInfo, path_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginInfo, create_symbol_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginInfo, delete_symbol_),
  };
  PluginInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PluginInfo_descriptor_,
      PluginInfo::default_instance_,
      PluginInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PluginInfo));
  PluginSet_descriptor_ = file->message_type(1);
  static const int PluginSet_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginSet, plugins_),
  };
  PluginSet_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PluginSet_descriptor_,
      PluginSet::default_instance_,
      PluginSet_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginSet, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PluginSet, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PluginSet));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_plugin_5fconf_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PluginInfo_descriptor_, &PluginInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PluginSet_descriptor_, &PluginSet::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_plugin_5fconf_2eproto() {
  delete PluginInfo::default_instance_;
  delete PluginInfo_reflection_;
  delete PluginSet::default_instance_;
  delete PluginSet_reflection_;
}

void protobuf_AddDesc_plugin_5fconf_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021plugin_conf.proto\022\tantifraud\"V\n\nPlugin"
    "Info\022\014\n\004name\030\001 \002(\t\022\014\n\004path\030\002 \002(\t\022\025\n\rcrea"
    "te_symbol\030\003 \001(\t\022\025\n\rdelete_symbol\030\004 \001(\t\"3"
    "\n\tPluginSet\022&\n\007plugins\030\001 \003(\0132\025.antifraud"
    ".PluginInfo", 171);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "plugin_conf.proto", &protobuf_RegisterTypes);
  PluginInfo::default_instance_ = new PluginInfo();
  PluginSet::default_instance_ = new PluginSet();
  PluginInfo::default_instance_->InitAsDefaultInstance();
  PluginSet::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_plugin_5fconf_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_plugin_5fconf_2eproto {
  StaticDescriptorInitializer_plugin_5fconf_2eproto() {
    protobuf_AddDesc_plugin_5fconf_2eproto();
  }
} static_descriptor_initializer_plugin_5fconf_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int PluginInfo::kNameFieldNumber;
const int PluginInfo::kPathFieldNumber;
const int PluginInfo::kCreateSymbolFieldNumber;
const int PluginInfo::kDeleteSymbolFieldNumber;
#endif  // !_MSC_VER

PluginInfo::PluginInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PluginInfo::InitAsDefaultInstance() {
}

PluginInfo::PluginInfo(const PluginInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PluginInfo::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  create_symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  delete_symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PluginInfo::~PluginInfo() {
  SharedDtor();
}

void PluginInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (path_ != &::google::protobuf::internal::kEmptyString) {
    delete path_;
  }
  if (create_symbol_ != &::google::protobuf::internal::kEmptyString) {
    delete create_symbol_;
  }
  if (delete_symbol_ != &::google::protobuf::internal::kEmptyString) {
    delete delete_symbol_;
  }
  if (this != default_instance_) {
  }
}

void PluginInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PluginInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PluginInfo_descriptor_;
}

const PluginInfo& PluginInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_plugin_5fconf_2eproto();  return *default_instance_;
}

PluginInfo* PluginInfo::default_instance_ = NULL;

PluginInfo* PluginInfo::New() const {
  return new PluginInfo;
}

void PluginInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    if (has_path()) {
      if (path_ != &::google::protobuf::internal::kEmptyString) {
        path_->clear();
      }
    }
    if (has_create_symbol()) {
      if (create_symbol_ != &::google::protobuf::internal::kEmptyString) {
        create_symbol_->clear();
      }
    }
    if (has_delete_symbol()) {
      if (delete_symbol_ != &::google::protobuf::internal::kEmptyString) {
        delete_symbol_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PluginInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_path;
        break;
      }
      
      // required string path = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_path:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_path()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->path().data(), this->path().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_create_symbol;
        break;
      }
      
      // optional string create_symbol = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_create_symbol:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_create_symbol()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->create_symbol().data(), this->create_symbol().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_delete_symbol;
        break;
      }
      
      // optional string delete_symbol = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_delete_symbol:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_delete_symbol()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->delete_symbol().data(), this->delete_symbol().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void PluginInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->name(), output);
  }
  
  // required string path = 2;
  if (has_path()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->path().data(), this->path().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->path(), output);
  }
  
  // optional string create_symbol = 3;
  if (has_create_symbol()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->create_symbol().data(), this->create_symbol().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->create_symbol(), output);
  }
  
  // optional string delete_symbol = 4;
  if (has_delete_symbol()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->delete_symbol().data(), this->delete_symbol().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->delete_symbol(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PluginInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }
  
  // required string path = 2;
  if (has_path()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->path().data(), this->path().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->path(), target);
  }
  
  // optional string create_symbol = 3;
  if (has_create_symbol()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->create_symbol().data(), this->create_symbol().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->create_symbol(), target);
  }
  
  // optional string delete_symbol = 4;
  if (has_delete_symbol()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->delete_symbol().data(), this->delete_symbol().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->delete_symbol(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PluginInfo::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }
    
    // required string path = 2;
    if (has_path()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->path());
    }
    
    // optional string create_symbol = 3;
    if (has_create_symbol()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->create_symbol());
    }
    
    // optional string delete_symbol = 4;
    if (has_delete_symbol()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->delete_symbol());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PluginInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PluginInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PluginInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PluginInfo::MergeFrom(const PluginInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_path()) {
      set_path(from.path());
    }
    if (from.has_create_symbol()) {
      set_create_symbol(from.create_symbol());
    }
    if (from.has_delete_symbol()) {
      set_delete_symbol(from.delete_symbol());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PluginInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PluginInfo::CopyFrom(const PluginInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PluginInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void PluginInfo::Swap(PluginInfo* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(path_, other->path_);
    std::swap(create_symbol_, other->create_symbol_);
    std::swap(delete_symbol_, other->delete_symbol_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PluginInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PluginInfo_descriptor_;
  metadata.reflection = PluginInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int PluginSet::kPluginsFieldNumber;
#endif  // !_MSC_VER

PluginSet::PluginSet()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PluginSet::InitAsDefaultInstance() {
}

PluginSet::PluginSet(const PluginSet& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PluginSet::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PluginSet::~PluginSet() {
  SharedDtor();
}

void PluginSet::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PluginSet::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PluginSet::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PluginSet_descriptor_;
}

const PluginSet& PluginSet::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_plugin_5fconf_2eproto();  return *default_instance_;
}

PluginSet* PluginSet::default_instance_ = NULL;

PluginSet* PluginSet::New() const {
  return new PluginSet;
}

void PluginSet::Clear() {
  plugins_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PluginSet::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .antifraud.PluginInfo plugins = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_plugins:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_plugins()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_plugins;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void PluginSet::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .antifraud.PluginInfo plugins = 1;
  for (int i = 0; i < this->plugins_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->plugins(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PluginSet::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .antifraud.PluginInfo plugins = 1;
  for (int i = 0; i < this->plugins_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->plugins(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PluginSet::ByteSize() const {
  int total_size = 0;
  
  // repeated .antifraud.PluginInfo plugins = 1;
  total_size += 1 * this->plugins_size();
  for (int i = 0; i < this->plugins_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->plugins(i));
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PluginSet::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PluginSet* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PluginSet*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PluginSet::MergeFrom(const PluginSet& from) {
  GOOGLE_CHECK_NE(&from, this);
  plugins_.MergeFrom(from.plugins_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PluginSet::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PluginSet::CopyFrom(const PluginSet& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PluginSet::IsInitialized() const {
  
  for (int i = 0; i < plugins_size(); i++) {
    if (!this->plugins(i).IsInitialized()) return false;
  }
  return true;
}

void PluginSet::Swap(PluginSet* other) {
  if (other != this) {
    plugins_.Swap(&other->plugins_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PluginSet::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PluginSet_descriptor_;
  metadata.reflection = PluginSet_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace antifraud

// @@protoc_insertion_point(global_scope)
