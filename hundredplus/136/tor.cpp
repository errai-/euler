#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

typedef unsigned long long int ull;

int main(void) {
    //const ull Uplim = 50;
    const ull Uplim = 50000000;
    unsigned *counts = new unsigned int[Uplim];

    for (ull a = 1; a < Uplim; ++a) {
        for (ull b = 1; a*b < Uplim; ++b) {
            if ((a+b)%4==0 and (3*a>b) and (3*a-b)%4==0)
                counts[a*b] += 1;
        }
    }

    ull count = 0;
    for (ull a = 0; a < Uplim; ++a) {
        if (counts[a] == 1) {
            //cout << a << " " << counts[a] << endl;
            ++count;
        }
        //cout << a.first << " " << a.second.size() << endl;
        //for (auto &b : a.second)
        //    cout << "  " << b << endl;
    }
    cout << endl << count << endl;
}
