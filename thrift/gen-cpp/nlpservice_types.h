/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef nlpservice_TYPES_H
#define nlpservice_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace nlpservice {

struct PosMap {
  enum type {
    PKU1 = 0,
    PKU2 = 1,
    ICT1 = 2,
    ICT2 = 3
  };
};

extern const std::map<int, const char*> _PosMap_VALUES_TO_NAMES;

typedef struct _IctclasWork__isset {
  _IctclasWork__isset() : sentence(false), posmap(true) {}
  bool sentence;
  bool posmap;
} _IctclasWork__isset;

class IctclasWork {
 public:

  static const char* ascii_fingerprint; // = "D6FD826D949221396F4FFC3ECCD3D192";
  static const uint8_t binary_fingerprint[16]; // = {0xD6,0xFD,0x82,0x6D,0x94,0x92,0x21,0x39,0x6F,0x4F,0xFC,0x3E,0xCC,0xD3,0xD1,0x92};

  IctclasWork() : sentence(), posmap((PosMap::type)0) {
    posmap = (PosMap::type)0;

  }

  virtual ~IctclasWork() throw() {}

  std::string sentence;
  PosMap::type posmap;

  _IctclasWork__isset __isset;

  void __set_sentence(const std::string& val) {
    sentence = val;
  }

  void __set_posmap(const PosMap::type val) {
    posmap = val;
  }

  bool operator == (const IctclasWork & rhs) const
  {
    if (!(sentence == rhs.sentence))
      return false;
    if (!(posmap == rhs.posmap))
      return false;
    return true;
  }
  bool operator != (const IctclasWork &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IctclasWork & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(IctclasWork &a, IctclasWork &b);


class InvalidOperation : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  InvalidOperation() {
  }

  virtual ~InvalidOperation() throw() {}


  bool operator == (const InvalidOperation & /* rhs */) const
  {
    return true;
  }
  bool operator != (const InvalidOperation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InvalidOperation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(InvalidOperation &a, InvalidOperation &b);

} // namespace

#endif
