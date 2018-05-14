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

const ll LIM = 1000000;

struct Sqr {
    ll inner;
    ll outer;
    ll cnt;
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
    ll stt = 4;
    for (ll n = 3; n<=LIM/4+1; ++n) {
        stt += 4;
        Sqr *jaa = new Sqr();
        jaa->inner = n;
        jaa->outer = n;
        jaa->cnt = stt;
        sqrs.push_back(jaa);
    }
    std::clock_t start = std::clock();
    ll place = 0;
    ll counter = 0;
    vector<string> visited;
    ll *counts = new ll[LIM+1];
    for (ll i = 0; i<=LIM; ++i) counts[i] = 0;
    while (place<sqrs.size()) {
        auto &now = *sqrs[place++];
        if (now.cnt<=LIM) {
            if (now.inner>4)
                sqrs.push_back(new Sqr(now,false));
            ++counter;
            counts[now.cnt] += 1;
        }
    }
    ll *ccc = new ll[16];
    for (ll i = 0; i<16; ++i) ccc[i] = 0;
    for (ll i = 1; i<=LIM; ++i) if (counts[i]<=15) ccc[counts[i]]++;
    for (ll i = 0; i<=15; ++i) cout << i << " " << ccc[i] << endl;
    ll garr = 0;
    for (ll i = 1; i<=10; ++i) garr += ccc[i];
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << " " << garr << endl;
    for (auto &j : sqrs) delete j;
}
