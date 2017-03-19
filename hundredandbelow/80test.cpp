#include "LongNumbers.h"
#include <iostream>
#include "80.h"

using std::cout;
using std::endl;

int main(void){

  uint64_t totalSum = 0;

  for (int i = 2; i != 100; ++i){
    if ( i==4 ) continue;
    if ( i==9 ) continue;
    if ( i==16 ) continue;
    if ( i==25 ) continue;
    if ( i==36 ) continue;
    if ( i==49 ) continue;
    if ( i==64 ) continue;
    if ( i==81 ) continue;
    if ( i==100 ) continue;
    Number ses(i);
    totalSum += ses.sumDecimals();
  }

  cout << totalSum << endl;
  return 0;
}
