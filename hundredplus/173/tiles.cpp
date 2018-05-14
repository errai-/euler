#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <fstream>
#include <set>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::set;

typedef unsigned long long int ull;
typedef long long int ll;
typedef unsigned long int uli;
typedef long int li;

const uli LIM = 1000000;

struct Sqr {
    uli inner;
    uli outer;
    uli cnt;
    Sqr() {
        inner = 3;
        outer = 3;
        cnt = 8;
    }
    Sqr(const Sqr &sr, bool cp = true) {
        inner = sr.inner;
        outer = sr.outer;
        cnt = sr.cnt;
        if (!cp) {
            inner -= 2;
            cnt += 4*(inner-1);
        }
    }
};


int main(void) {
    vector<Sqr*> sqrs;
    uli stt = 4;
    for (uli n = 3; n<=LIM/4+1; ++n) {
        stt += 4;
        Sqr *jaa = new Sqr();
        jaa->inner = n;
        jaa->outer = n;
        jaa->cnt = stt;
        sqrs.push_back(jaa);
    }
    std::clock_t start = std::clock();
    uli place = 0;
    uli counter = 0;
    vector<string> visited;
    while (place<sqrs.size()) {
        auto &now = *sqrs[place++];
        if (now.cnt<=LIM) {
            if (now.inner>4)
                sqrs.push_back(new Sqr(now,false));
            ++counter;
        }
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
    for (auto &j : sqrs) delete j;
}
