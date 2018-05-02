#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <fstream>
#include <random>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

typedef unsigned long long int ull;


int main(void) {
  std::mt19937_64 ge;
  std::uniform_int_distribution<int> peter(1,4);
  std::uniform_int_distribution<int> colin(1,6);
  cout << std::fixed << std::setprecision(8);
  double reps=0.0, pwins=0.0;
  for (int i=0; i<=100000000000; ++i) {
    int pet = 0;
    for (int j=0; j<9; ++j) pet += peter(ge);
    int col = 0;
    for (int j=0; j<6; ++j) col += colin(ge);
    if (pet>col) pwins += 1.0;
    reps += 1.0;
    if (i%1000000==0) cout << i << " " << pwins/reps << endl;
  }
}
