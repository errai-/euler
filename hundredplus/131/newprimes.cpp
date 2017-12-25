#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using std::map;
using std::vector;
using std::cout;
using std::endl;
using std::pow;
using std::pair;

typedef unsigned long long ull;
#define ARRAY (100000)
#define UPLIM (1000000)
bool sieve[UPLIM+1];
ull primes[ARRAY];
const ull wheel[] = {1,7,11,13,17,19,23,29};


inline void sievize(unsigned long long num) {
    bool goodvals = true;
    ull wc = 0;
    while (goodvals) {
        for (auto & val : wheel) {
            ull n = wc+val*num;
            if (n>UPLIM) {
                goodvals = false;
                break;
            }
            sieve[n] = true;
        }
        wc += 30*num;
    }
}

unsigned cumulateprimes() {
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    ull curr = 3;
    ull rounds = UPLIM/30;
    ull leftover = UPLIM%30;
    for (auto & p : wheel) {
        if (p==1)
            continue;
        if (!sieve[p]) {
            primes[curr++] = p;
            sievize(p);
        }
    }
    ull wc = 30;
    for (auto whs = 1u; whs < rounds; ++whs) {
        for (auto & w : wheel) {
            auto p = wc + w;
            if (!sieve[p]) {
                primes[curr++] = p;
                sievize(p);
            }
        }
        wc += 30;
    }
    for (auto & w : wheel) {
        auto p = wc + w;
        if (p>UPLIM)
            break;
        if (!sieve[p])
            primes[curr++] = p;
    }

    return curr;
}

inline bool isprime(ull num,ull lp) {
    if (num<2)
        return false;
    if (num<primes[lp-1]) {
        if (std::binary_search(primes,primes+lp,num))
            return true;
        else
            return false;
    }
    ull lim = pow(num,0.5)+1;
    for (auto i = 0u; i < lp and primes[i]<lim; ++i)
        if (num%primes[i]==0)
            return false;
    return true;
}

vector<pair<ull,ull> > divisors3p2(ull num) {
    vector< pair<ull,ull> > res;
    ull limit = static_cast<ull>(pow(static_cast<double>(num),0.5));
    for (auto i = 0u; primes[i] <= limit; ++i) {
        auto p = primes[i];
        if (num%p==0) {
            ull divs = 0;
            while (num%p==0) {
                num /= p;
                divs += 1;
            }
            ull surplus = (divs%3==0) ? 0 : 1;
            divs *= 2;
            divs /= 3;
            divs = divs + surplus;
            res.push_back(std::make_pair(p,divs));
            limit = static_cast<ull>(pow(static_cast<double>(num),0.5));
        }
    }
    if (num>1)
        res.push_back(std::make_pair(num,2));
    return res;
}

bool testdivs(ull mnum, vector<pair<ull,ull> > divs) {
    for (auto & div : divs) {
        for (auto i = 0; i < div.second; ++i) {
            if (mnum%div.first != 0)
                return false;
            mnum /= div.first;
        }
    }
    return true;
}

int main(void) {
    auto limit = cumulateprimes();

    unsigned sump = 0;
    for (auto i = 0u; i < limit and primes[i]<UPLIM; ++i) {
        ull difflim = primes[i]/3;
        double dlim = 1;//static_cast<double>(difflim);
        for (double o = 1; o <= dlim; ++o) {
            double alph = static_cast<double>(primes[i])/(3*o)-1;
            double inner = 1+pow(1+(4.0/3.0)*alph,0.5);
            double n = o/(2*alph);
            n *= inner;
            double nr = std::round(n);
            if (fabs(nr-n) < 0.001) {
                ull ms = static_cast<ull>(nr+o);
                ull ns = static_cast<ull>(nr);
                auto divs = divisors3p2(ns);
                if (testdivs(ms,divs)) {
                    double frac = pow(nr+o,1.5)/nr;
                    frac = std::round(pow(frac,2));
                    ull p = static_cast<ull>(frac) - ns;
                    if (p==primes[i]) {
                        ++sump;
                        cout << primes[i] << " " << sump << endl;
                        //cout << primes[i] << " " << p << " " << frac << " " << ms << "**3 - " << ns << "**3 - " << primes[i] << "*" << ns << "**2" << endl;

                        //for (auto & dd : divs)
                        //    cout << dd.first << " " << dd.second << endl;
                        break;
                    }
                }
            }
        }
    }
    cout << sump << endl;
}
