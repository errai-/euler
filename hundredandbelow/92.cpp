#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;
using std::clock_t;
using std::set;

const int squareTable[10] = {0,1,4,9,16,25,36,49,64,81};

int nextNo(int currNo){
  int newNo=0;
  while (currNo!=0){
    int currDig = currNo % 10;
    newNo += squareTable[currDig];
    currNo /= 10;
  }
  return newNo;
}

bool Is89(int number){
  if (number==89){
    return true;
  }
  if (number==1){
    return false;
  }
  int next = nextNo(number);
  return Is89(next);
}

int main(void){
  clock_t start = clock();
  set<int> leaders89;
  set<int> leaders1;
  leaders89.insert(89); leaders1.insert(1);
  int counter = 0;
  for (int i=1; i!=10000000; ++i){
    vector<int> tmpStore;
    if (Is89(i)) counter++;
  }

  cout << "Ans: " << counter << " Time: ";
  cout << (clock()-start)/((double)CLOCKS_PER_SEC) << "s" << endl;
  return 0;
}
