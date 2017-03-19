#include <iostream>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::uint64_t;
using std::clock_t;

bool CompatibleSides(int x,int y,int relx,int rely, int side1){
  int side2, side3, tmpSide;
  side2 = pow(x,2)+pow(y,2); side3 = pow(relx,2)+pow(rely,2);
  if (side1>side3){
    tmpSide = side3; side3 = side1; side1 = tmpSide;
  }
  if (side2>side3){
    tmpSide = side3; side3 = side2; side2 = tmpSide;
  }
  return side1 + side2 == side3;
}

int main(void){
  size_t triangleCount=0;
  clock_t start = clock();
  for(int py=0; py!=51; ++py){
    for(int px=0; px!=51; ++px){
      int side1 = pow(px,2)+pow(py,2);
      if (side1==0) continue;
      if(px!=50){
        for(int qx=px+1; qx!=51; ++qx){
          if (CompatibleSides(qx,py,qx-px,0,side1)) triangleCount++;
        }
      }
      if(py!=50){
        for(int qy=py+1; qy!=51; ++qy){
          for(int qx=0; qx!=51; ++qx){
            if (CompatibleSides(qx,qy,qx-px,qy-py,side1)) triangleCount++;
          }
        }
      }
    }
  }
  cout << "Ans: " << triangleCount << " Time: ";
  cout << (clock()-start)/((double)CLOCKS_PER_SEC) << "s" << endl;
  return 0;
}
