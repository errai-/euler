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

#define SQRLIM 1000000
#define LIM 1000000000000

void repfind(const ull n, vector<ull> &repu) {
    ull lim = static_cast<ull>(ceil(static_cast<float>(LIM-1)/static_cast<float>(n)));
    ull val = n+1;
    while (val<lim) {
        val *= n;
        ++val;
        auto valplace = std::lower_bound(repu.begin(),repu.end(),val);
        if (valplace==repu.end() or *valplace!=val)
            repu.insert(valplace,val);
    }
}


int main(void) {
    vector<ull> srepunits = {1};
    srepunits.reserve(SQRLIM);

    for (ull n = 2; n<SQRLIM; ++n) {
        cout << n << endl;
        repfind(n,srepunits);
    }

    ull sum = 0;
    for (auto &r: srepunits)
        sum += r;
    cout << "Sum: " << sum << endl;
}
