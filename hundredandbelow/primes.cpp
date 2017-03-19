#include "primes.h"

Primes::Primes(uint64_t smallerThan){
  primeArray.push_back(2);
  primeArray.push_back(3);
  continueSearch = 3;
  while ( findNextPrime() <= smallerThan );
}

bool Primes::isPrime() const{
  uint64_t limit = uint64_t( sqrt( continueSearch ) );
  uint64_t idx = 0;
  while( primeArray[idx] <= limit ){
    if ( continueSearch%primeArray[idx] == 0 ) 
      return false;
    ++idx;
  }
  return true;
}

uint64_t Primes::findNextPrime(){
  continueSearch += 2;
  while( !isPrime() ){
    continueSearch += 2;
  }
  primeArray.push_back(continueSearch);
  return continueSearch;
}

uint64_t Primes::equalOrSmaller(uint64_t probe) const{
  uint64_t cumulation = 0;
  while ( primeArray[cumulation] <= probe ){
    ++cumulation;
  }
  return cumulation;
}

bool Primes::primeness(uint64_t probe) const{
  uint64_t idx = equalOrSmaller(probe);
  if (idx == 0) return false;
  return probe == primeArray[idx-1];
}
