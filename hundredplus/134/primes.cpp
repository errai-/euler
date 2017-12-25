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

typedef unsigned long long ull;
#define ARRAY (100000)
#define UPLIM (1001000)
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

int main() {
    auto limit = cumulateprimes();
    ull sumnums = 0;
    for (auto i = 2u; primes[i] < 1000000; ++i) {
        auto p1 = primes[i];
        auto p2 = primes[i+1];
        cout << p1 << endl;
        ull alpha = static_cast<ull>(pow(10,ceil(log10(p1))));
        ull curr = p2-p1;
        //ull m = 1;
        while (true) {
            if (curr%alpha==0) {
                //m = curr/alpha;
                break;
            }
            curr += p2;
        }
        sumnums += curr + p1;
        //cout << p1 << " " << p2 << " " << curr+p1 << " " << alpha*m + p1 << endl;
    }
    cout << sumnums << endl;
}
