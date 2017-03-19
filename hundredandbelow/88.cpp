#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include "primes.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;
using std::set;

class Monster{
private:
  vector<int> fillerNo;
  Primes primeStore;
  vector< vector<int> > choices;
  int nextStudy;
public:
  // fillerNo, values 2->limit, choices begins from 4
  Monster(int target, int primeLim): fillerNo(target,0),primeStore(primeLim)
    {nextStudy=4;}
  ~Monster(){ }
  int fillStudies();
  uint64_t sumOfCells();
  void printFills(){
    for (size_t i = 0; i != fillerNo.size(); ++i){
      cout << fillerNo[i] << endl;
    }
  }
};

int Monster::fillStudies(){
  if ( primeStore.primeness(nextStudy) ){
    nextStudy++; 
    vector<int> dummy;
    dummy.push_back(0);
    choices.push_back(dummy);
    return 0;
  }
  int studyLimit = int(sqrt(nextStudy))+1;
  set<int> feasibleAmounts;
  for (int i = 2; i != studyLimit; ++i){
    if ( nextStudy%i == 0 ){
      int dummy = nextStudy/i;
      int zeroPointAmount = nextStudy-i-dummy+2;
      feasibleAmounts.insert( zeroPointAmount );
      if ( primeStore.primeness(dummy) ) continue;
      int innerLimit = choices[dummy-4].size();
      for (int j = 0; j != innerLimit; ++j){
        feasibleAmounts.insert( (choices[dummy-4])[j] + zeroPointAmount );
      }
    }
  }
  vector<int> pushable;
  int counter = 0;
  for (auto iter=feasibleAmounts.begin(); iter!=feasibleAmounts.end(); ++iter){
    if (fillerNo.size()+1<size_t(*iter)) break;
    pushable.push_back(*iter-1);
    if (fillerNo[*iter-2]==0){
      fillerNo[*iter-2]=nextStudy;
      ++counter;
    }
  }

  choices.push_back(pushable);
  nextStudy++;
  return counter;
}

uint64_t Monster::sumOfCells(){
  uint64_t looper = 0;
  set<int> numeros;
  for (size_t i = 0; i != fillerNo.size(); ++i){
    numeros.insert(fillerNo[i]);
  }
  for (auto iter = numeros.begin(); iter != numeros.end(); ++iter){
    looper += *iter;
  }
  return looper;
}

int main(void){
  int limit = 12000;
  int loopLim = limit*2+1;
  int primeLim = loopLim/2;
  Monster generalStorage( limit-1, primeLim );
  int cumulativeSum = 0;

  for (int i = 4; i != loopLim; ++i){
    cumulativeSum += generalStorage.fillStudies();
    if (cumulativeSum >= limit-1) break;
  }
  cout << generalStorage.sumOfCells() << endl;
  return 0;
}
