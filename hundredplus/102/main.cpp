#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::vector;
using std::stringstream;

bool correcto(int& x1, int& y1, int& x2, int& y2, int sign) {
    return sign*(x1*y2 - x2*y1) <= 0;
}

bool three_correct( vector<int>& x, vector<int>& y ) {
    int sign = x[2]*(y[1]-y[0])-y[2]*(x[1]-x[0]);
    if ( sign < 0 ) sign = -1;
    else sign = 1;

    for ( unsigned i = 0; i < 3; ++i ) {
        if ( !correcto(x[i],y[i],x[(i+1)%3],y[(i+1)%3],sign) )
            return false;
    }
    return true;
}

void split(const string& s, char c,
           vector<string>& v) {
   int i = 0;
   int j = s.find(c);

   while (j >= 0) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j < 0) {
         v.push_back(s.substr(i, s.length()));
      }
   }
}

int main(void) {
    vector<int> x(3);
    vector<int> y(3);
    std::ifstream fil("p102_triangles.txt");
    string line;
    int counter = 0, corrects = 0;
    while( fil.is_open() ) {
        std::getline(fil,line);
        vector<string> tmpv;
        split(line,',',tmpv);
        for ( unsigned i = 0; i < 3; ++i ) {
            x[i] = std::stoi(tmpv[2*i],nullptr,10);
            y[i] = std::stoi(tmpv[2*i+1],nullptr,10);
        }

        if (three_correct( x, y ))
            ++corrects;
        if ( ++counter==1000 )
            break;
    }
    cout << corrects << endl;
    return 0;
}
