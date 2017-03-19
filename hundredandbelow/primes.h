#ifndef PRIMES_H
#define PRIMES_H

#include <cmath>
#include <iostream>
#include <vector>
#include <cstdint>

using std::vector;
using std::uint64_t;

class Primes{
private:
  vector<uint64_t> primeArray;
  uint64_t continueSearch;
public:
  Primes() {primeArray.push_back(2); primeArray.push_back(3); continueSearch = 3;}
  Primes(uint64_t smallerThan);
  ~Primes(){ }
  uint64_t primeAmount() const { return primeArray.size(); }
  uint64_t largestPrime() const { return primeArray[ primeArray.size() - 1 ]; }
  uint64_t getPrime( uint64_t idx ) const { return primeArray[ idx%primeAmount() ]; }
  uint64_t operator[](uint64_t idx) const { return getPrime( idx ); }
  bool isPrime() const;
  uint64_t findNextPrime();
  uint64_t equalOrSmaller(uint64_t probe) const;
  bool primeness(uint64_t probe) const;
};

#endif // PRIMES_H
