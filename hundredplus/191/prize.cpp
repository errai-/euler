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

#define NN 30

ull factorial(ull up, ull dwn) {
    ll comb = 1;
    for (ull i = up; i> dwn; --i) comb *= i;
    return comb;
}

ll combos(ll f, ll s) {
    ll mf = std::max(f,s);
    ll ms = std::min(f,s);
    ll up = factorial(mf+ms,mf);
    up /= factorial(ms,1);
    return up;
}

struct Prob {
    ll na;
    ll n2a;
    ll N;
    Prob() {
        na = 0;
        n2a = 0;
        N = 0;
    }
    Prob(const Prob &s) {
        na = s.na;
        n2a = s.n2a;
        N = s.N;
    }
    ll nmove() {
        return N+1-3*n2a-2*na;
    }
    ll n0() {
        return N-2*n2a-na;
    }
    ll comb() {
        ll n0ways = n0()+1;
        if (n2a==0 and na==0)
            return n0ways;
        ll basketsm = n2a+na;
        ll ways = combos(basketsm,nmove());
        ll aways = combos(n2a,na);
        return ways*aways*n0ways;
    }
};

int main(void) {
    ull counter = 0;
    vector<Prob*> nuus;
    for (ull i = 0; i<=(NN+1)/3; ++i) {
        Prob *jaa = new Prob();
        jaa->n2a = i;
        jaa->N = NN;
        nuus.push_back(jaa);
    }
    std::clock_t start = std::clock();
    for (ull i = 0; i < nuus.size(); ++i) {
        auto &snuu = *nuus[i];
        ll move = snuu.nmove();
        cout << "j" << snuu.n2a << " " << snuu.na << " " << move << endl;
        if (move>=0) {
            counter += snuu.comb();
            Prob *jaa = new Prob(snuu);
            jaa->na += 1;
            nuus.push_back(jaa);
        }
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
    for (auto &j : nuus) delete j;
}
