#include <iostream>
#include <math.h>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;

class Identifier{
private:
  uint64_t lower;
  uint64_t upper;
public:
  bool hasEvenHypot();
  uint64_t highDomAmount();
  uint64_t highLowAmount();
  Identifier( uint64_t lo, uint64_t up ){
    lower = lo;
    upper = up;
  }
};

bool Identifier::hasEvenHypot(){
  uint64_t tmpVal = pow( lower, 2 ) + pow( upper, 2 );
  double unRounded = sqrt( tmpVal );
  double rounded = (double) ( (uint64_t) unRounded );
  return rounded == unRounded;
}

uint64_t Identifier::highDomAmount(){
  return lower/2;
}

uint64_t Identifier::highLowAmount(){
  uint64_t studyAmount = 2*lower-upper+2;
  return studyAmount/2;
}

int main(void){

  uint64_t arbitraryLimit = 4001;
  vector<uint64_t> storage(arbitraryLimit-1,0);
  uint64_t runner = 2;
  uint64_t cumulative = 0;
  while (runner < arbitraryLimit ){
    uint64_t lowRunner = 2;
    while (lowRunner < runner){
      Identifier probe( lowRunner, runner );
      if (probe.hasEvenHypot()){
        storage[runner-1] += probe.highDomAmount();
        storage[lowRunner-1] += probe.highLowAmount();
      }
      ++lowRunner;
    }
    if (runner%2 == 0){
      cumulative += storage[runner/2-1];
      cout << "Ready M = " << runner/2 << " cuboids " << cumulative << endl;
    }
    ++runner;
  }


  return 0;
}
