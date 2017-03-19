#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "primes.h"
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using lint = std::uint64_t;
using vekt = vector<lint>;

int main(void){
  lint limit = 50000000;
  lint squareLim = lint( pow( limit, 0.5 ) );
  Primes primes( squareLim );

  vekt squares, cubes, quadrs;
  lint idx = 0; lint power = lint( pow(primes[idx],2) );
  while ( power < limit ){
    squares.push_back( power );
    ++idx;
    power = lint( pow(primes[idx],2) );
  }
  idx = 0; power = lint( pow(primes[idx],3) );
  while ( power < limit ){
    cubes.push_back( power );
    ++idx;
    power = lint( pow(primes[idx],3) );
  }
  idx = 0; power = lint( pow(primes[idx],4) );
  while ( power < limit ){
    quadrs.push_back( power );
    ++idx;
    power = lint( pow(primes[idx],4) );
  }

  std::set<lint> storageRoom;

  for (size_t i = 0; i != quadrs.size(); ++i){
    for (size_t j = 0; j != cubes.size(); ++j){
      lint medium = quadrs[i]+cubes[j];
      if (medium >= limit)
        break;
      for (size_t k = 0; k != squares.size(); ++k){
        lint large = medium + squares[k];
        if (large >= limit)
          break;
        storageRoom.insert( large );
      }
    }
  }
  cout << storageRoom.size() << endl;
  return 0;
}
