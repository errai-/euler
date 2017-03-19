#ifndef EX80_H
#define EX80_H

#include <iostream>
#include <math.h>
#include <cstdint>
#include "LongNumbers.h"

using std::uint64_t;
using std::uint32_t;
using std::uint8_t;


class Number
{
private:
  uint756_t origNo;
  uint756_t root;
  HugeDouble decimalTable[1242];
  HugeDouble squareRoot;

public:

  void fillDecimals(){
    HugeDouble tmpDouble(1);
    for (uint64_t i = 0; i != 1242; ++i){
      tmpDouble /= 2;
      decimalTable[i] = tmpDouble;
    }
  }

  void rootCalc(){
    const uint756_t zero;
    uint756_t square;
    uint756_t tmpNo = origNo;
    square.bits[11] = 1;
    square <<= 754;
    while (square > origNo){
      square >>= 2;
    }
    int iter = 0;
    while (square != zero){
      uint756_t tmpSum = root + square;
      if (tmpNo >= tmpSum){
        tmpNo -= tmpSum;
        root >>= 1;
        root += square;
      } else {
        root >>= 1;
      }
      square >>= 2;
    }

    root <<= 621;
  }

  void updateTen(){
    HugeDouble tmp( root, decimalTable );
    squareRoot = tmp;
  }

  Number(){ }

  Number(uint64_t init){
    if ( init < 262144 ){
      uint756_t filler(init);
      origNo = filler;
    }
    fillDecimals();
    rootCalc();
    updateTen();
  }

  ~Number(){ }

  void print(){
    updateTen();
    cout << squareRoot;
  }

  uint64_t sumDecimals(){
    return squareRoot.decimalSum();
  }
};

#endif // EX80_H
