#include <iostream>
#include <vector>
#include <cstdint>
#include <math.h>

using std::vector;
using std::cout;
using std::endl;
using std::uint64_t;

class Rectangles{
private:
  uint64_t area;
  vector<uint64_t> width;
  vector<uint64_t> height;
  vector<uint64_t> amounts;
public:
  void rectAmounts();
  void scrollSizes();
  Rectangles(uint64_t _area){
    area = _area;
    scrollSizes();
    rectAmounts();
  }
  ~Rectangles(){ }
  uint64_t diff();
};

void Rectangles::scrollSizes(){
  uint64_t limit = (uint64_t) (sqrt(area)+1);
  for (uint64_t wProbe = 1; wProbe != limit; ++wProbe){
    double rounded = (double) ( area/wProbe );
    double unRounded = (double) ( ((double) area)/wProbe );
    if (rounded == unRounded){
      width.push_back(wProbe);
      height.push_back(area/wProbe);
    }
  }
}

void Rectangles::rectAmounts(){
  for (int i = 0; i != width.size(); ++i){
    uint64_t w = ( width[i]*(width[i]+1))/2;
    uint64_t h = ( height[i]*(height[i]+1))/2;
    amounts.push_back( w*h );
  }
}

uint64_t Rectangles::diff(){
  uint64_t initDiff = abs( 2000000 - amounts[0]);
  for (int i = 1; i != amounts.size(); ++i){
     uint64_t tmpDiff = abs(2000000-amounts[i]);
     if ( tmpDiff < initDiff ){
      initDiff = tmpDiff;
    }
  }
  return initDiff;
}

int main(void){

  uint64_t currArea = 1999;
  int difference = 2000000;
  uint64_t bestArea = 0;
  while (currArea < 2777){
    Rectangles rekt(currArea);
    if (rekt.diff() < difference){
      difference = rekt.diff();
      bestArea = currArea;
    }
    currArea++;
  }
  cout << "Best area " << bestArea << " with difference " << difference << endl;
  return 0;
}
