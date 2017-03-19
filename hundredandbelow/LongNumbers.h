#ifndef LONGNUMBERS_H
#define LONGNUMBERS_H

#include <iostream>
#include <math.h>
#include <cstdint>

using std::uint64_t;
using std::uint32_t;
using std::uint64_t;
using std::ostream;
using std::cout;
using std::endl;

struct uint756_t {
  static const uint64_t bitNo = 20;
  uint64_t bits[bitNo];

  uint756_t(){
    for (uint64_t i = 0; i != bitNo; ++i){
      bits[i]=0;
    }
  }

  uint756_t(uint64_t starter){
    bits[0] = (starter << 46) >> 1;
    for (uint64_t i = 1; i != bitNo; ++i){
      bits[i]=0;
    }
  }

  uint756_t operator<<(uint64_t shift) const{
    uint756_t dummy = (*this);
    uint64_t shortenedBitNo = bitNo - 1;
    uint64_t iterations = (uint64_t) ( shift/63 );
    for (uint64_t j = 0; j != iterations; ++j){
      for (uint64_t i = 0; i != shortenedBitNo; ++i){
        dummy.bits[i] = dummy.bits[i+1];
      }   
      dummy.bits[shortenedBitNo] = 0;
    }
    shift = shift%63;
    for (uint64_t i = 0; i != shortenedBitNo; ++i){
      dummy.bits[i] = ( ( (dummy.bits[i]<<(shift+1))>>1)  | (dummy.bits[i+1]>>(63-shift)) );
    }   
    dummy.bits[shortenedBitNo] = ( (dummy.bits[shortenedBitNo]<<(shift+1))>>1 );
    return dummy;
  }

  uint756_t operator>>(uint64_t shift) const{
    uint756_t dummy = (*this);
    uint64_t shortenedBitNo = bitNo - 1;
    uint64_t iterations = (uint64_t) ( shift/63 );
    for (uint64_t j = 0; j != iterations; ++j){
      for (uint64_t i = 0; i != shortenedBitNo; ++i){
        dummy.bits[shortenedBitNo-i] = dummy.bits[shortenedBitNo-1-i];
      }   
      dummy.bits[0] = 0;
    }
    shift = shift%63;
    for (uint64_t i = 0; i != shortenedBitNo; ++i){
      dummy.bits[shortenedBitNo-i] = 
        ( ((dummy.bits[shortenedBitNo-1-i]<<(64-shift))>>1) | 
        (dummy.bits[shortenedBitNo-i]>>shift) );
    }   
    dummy.bits[0] = ( dummy.bits[0]>>shift );
    return dummy;
  }

  uint756_t operator<<=(uint64_t shift){
    (*this) = (*this) << shift;
  }

  uint756_t operator>>=(uint64_t shift){
    (*this) = (*this) >> shift;
  }

  bool operator!=(const uint756_t &right) const{
    for (uint64_t i = 0; i != bitNo; ++i){
      if ( bits[i] != right.bits[i] ) return true;
    }
    return false;
  }

  bool operator>(const uint756_t &right) const{
    for (uint64_t i = 0; i != bitNo; ++i){
      if ( bits[i] > right.bits[i] ) return true;
    }
    return false;
  }

  bool operator>=(const uint756_t &right) const{
    for (uint64_t i = 0; i != bitNo; ++i){
      if ( bits[i] > right.bits[i] ) { return true;}
      if ( bits[i] < right.bits[i] ) { return false;}
    }
    return true;
  }

  uint756_t operator=(const uint756_t &right){
    for (uint64_t i = 0; i != bitNo; ++i){
      bits[i] = right.bits[i];
    }
    return (*this);
  }

  void adder( uint64_t &over, uint64_t added, uint64_t idx ){
    bits[idx] += added;
    if ( bits[idx] & ( ( (uint64_t) 1) << 63 ) ){
      over += 1;
    }
    bits[idx] = ( bits[idx] << 1 ) >> 1;
  }

  uint756_t operator+=(const uint756_t &right){
    uint64_t over = 0;
    for (uint64_t i = 0; i != bitNo; ++i){
      uint64_t idx = bitNo-1-i;
      uint64_t tmpOver = over;
      over = 0;
      adder( over, tmpOver, idx );
      adder( over, right.bits[idx], idx );
    }
  }

  uint756_t operator+(const uint756_t &right) const {
    uint756_t tmpInt;
    tmpInt = (*this);
    tmpInt += right;
    return tmpInt;
  }

  void substr( uint64_t &under, uint64_t removed, uint64_t idx ){
    if ( removed > bits[idx] ){
      under += 1;
      bits[idx] = bits[idx] | (( (uint64_t) 1) << 63);
    }
    bits[idx] -= removed;
  }

  uint756_t operator-=(const uint756_t &right){
    uint64_t under = 0;
    for (uint64_t i = 0; i != bitNo; ++i){
      uint64_t idx = bitNo-1-i;
      uint64_t tmpUnder = under;
      under = 0;
      substr( under, tmpUnder, idx );
      substr( under, right.bits[idx], idx );
    }
  }

};

struct HugeDouble {
  static const uint64_t noSize = 140;
  uint64_t number[noSize];
  const uint64_t powerDifference = (uint64_t) pow( 10, 11 );

  HugeDouble &operator+=(const HugeDouble &right){
    uint64_t addition = 0;
    for (uint64_t i = 0; i != noSize; ++i){
      uint64_t idx = noSize-1-i;
      number[idx] += right.number[idx];
      number[idx] += addition;
      addition = (uint64_t) ( (number[idx])/powerDifference );
      number[noSize-1-i] = (uint64_t) ( (number[idx])%powerDifference );
    }
    return (*this);
  }

  HugeDouble &operator*=(uint64_t coefficient){
    uint64_t addition = 0;
    for (uint64_t i = 0; i!= noSize; ++i){
      uint64_t idx = noSize-1-i;
      number[idx] *= coefficient;
      number[idx] += addition;
      addition = (uint64_t) ( (number[idx])/powerDifference );
      uint64_t substitute = (uint64_t) ( (number[idx])%powerDifference );
      number[idx] = substitute;
    }
    return (*this);
  }

  // This is meant for simple divisions, i.e. for example division with 2
  HugeDouble &operator/=(uint64_t coefficient){
    for (uint64_t i = 0; i != noSize; ++i){
      uint64_t remaining = number[i]%coefficient;
      remaining *= powerDifference;
      number[i] /= coefficient;
      if (i!=noSize-1){
        number[i+1] += remaining;
      }
    }
    return (*this);
  }

  HugeDouble &operator=(HugeDouble &right){
    for (uint64_t i = 0; i != noSize; ++i){
      number[i] = right.number[i];
    }
    return (*this);
  }
  
  HugeDouble(){
    for (uint64_t i = 0; i != noSize; ++i){
      number[i] = 0;
    }   
  }

  HugeDouble(int64_t initialize){
    number[0] = initialize;
    for (uint64_t i = 1; i != noSize; ++i){
      number[i] = 0;
    }
  }

  HugeDouble(const HugeDouble &initDouble, uint64_t coefficient){
    for (uint64_t i = 0; i != noSize; ++i){
      number[i] = initDouble.number[i];
    }
    (*this) *= coefficient;
  }

  HugeDouble(const uint756_t &binaryForm, const HugeDouble *binaryTable){
    for (uint64_t i = 0; i != noSize; ++i){
      number[i] = 0;
    }
    uint64_t interest = 1;
    interest <<= 62;
    uint64_t idx = 0;
    for (uint64_t i = 0; i != 18; ++i){
      uint64_t indicator = binaryForm.bits[idx] & interest;
      interest >>= 1;
      if (!indicator) continue;
      number[0] += (uint64_t) pow( 2, 17-i );
    }
    for (uint64_t i = 0; i != 738; ++i){
      if (interest == 0){
        interest = 1;
        interest <<= 62;
        ++idx;
      }
      uint64_t indicator = binaryForm.bits[idx] & interest;
      interest >>= 1;
      if (!indicator) continue;
      (*this) += binaryTable[i];
    }
  }

  ~HugeDouble(){ }

  uint64_t decimal( uint64_t place ){
    uint64_t idx = (uint64_t) place/11;
    uint64_t location = (uint64_t) pow( 10, 10-place%11 );
    uint64_t value = number[idx]/location;
    value = value%10;
    return value;
  }

  uint64_t decimalSum(){
    uint64_t startLoc = 0;
    for (uint64_t i = 0; i != noSize; ++i){
      if (number[i] != 0){
        startLoc += (uint64_t) (10 - ( (uint64_t) log10( number[i] )) );
        break;
      }
      startLoc += 11;
    }
    uint64_t dSum = 0;
    for (uint64_t i = 0; i != 100; ++i){
      dSum += decimal( startLoc+i );
    }
    return dSum;
  }

  friend ostream &operator<<(ostream &out, const HugeDouble &printNumber){
    out << printNumber.number[0] << ".";
    for (uint64_t i = 1; i != noSize; ++i){
      uint64_t zeros = (uint64_t) log10( printNumber.number[i] )+1;
      if (zeros < 11){
        uint64_t addZeros = 11-zeros;
        for (uint64_t i = 0; i != addZeros; ++i){
          out << "0";
        }
      }
      out << printNumber.number[i];
    }
  }

};

#endif // LONGNUMBERS_H
