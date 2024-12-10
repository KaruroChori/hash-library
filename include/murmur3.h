//-----------------------------------------------------------------------------
// MurmurHash3 was written by Austin Appleby, and is placed in the public
// domain. The author hereby disclaims copyright to this source code.

#pragma once

//-----------------------------------------------------------------------------
// Platform-specific functions and macros

#include "hl-types.h"
#include <string>

//-----------------------------------------------------------------------------

void MurmurHash3_x86_32  ( const void * key, int len, uint32_t seed, void * out );

void MurmurHash3_x86_128 ( const void * key, int len, uint32_t seed, void * out );

void MurmurHash3_x64_128 ( const void * key, int len, uint32_t seed, void * out );

template<int SIZE = 128>
void murmur3 ( const void * key, int len, uint32_t seed, uint8_t out[SIZE/8] ){
    if(SIZE==32){return MurmurHash3_x86_32(key, len, seed, out);}
    else if(SIZE==128 && sizeof(void*)==4){return MurmurHash3_x86_128(key, len, seed, out);}
    else if(SIZE==128){return MurmurHash3_x64_128(key, len, seed, out);}
}

//TODO: Implement an interface more or less like the others.

//-----------------------------------------------------------------------------

/*
class Murmur3 //: public Hash
{
public:
  /// algorithm variants
  enum Bits { Bits128 = 128 };
  enum { HashBytes = 128/8 };


  /// same as reset()
  explicit Murmur3(Bits bits = Bits128, uint32_t seed = 0);

  /// compute hash of a memory block
  std::string operator()(const void* data, size_t numBytes);
  /// compute hash of a string, excluding final zero
  std::string operator()(const std::string& text);

  /// add arbitrary number of bytes
  void add(const void* data, size_t numBytes);

  /// return latest hash as hex characters
  std::string getHash();
  void        getHash(unsigned char buffer[HashBytes]);

  /// restart
  void reset();

private:
  /// process a full block
  //void processBlock(const void* data);
  /// process everything left in the internal buffer
  //void processBuffer();

  /// hash
  uint32_t seed;
};
*/