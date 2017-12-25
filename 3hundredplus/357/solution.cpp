#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;
using std::pow;

#define ARRAY (10000000)
#define UPLIM (100000000)
bool sieve[UPLIM+1];
unsigned primes[ARRAY];
const unsigned wheel[] = {1,7,11,13,17,19,23,29};

inline void sievize(unsigned long long num) {
    bool goodvals = true;
    unsigned long long wc = 0;
    while (goodvals) {
        for (auto & val : wheel) {
            unsigned long long n = wc+val*num;
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
    unsigned long long curr = 3;
    unsigned long long rounds = UPLIM/30;
    unsigned long long leftover = UPLIM%30;
    for (auto & p : wheel) {
        if (p==1)
            continue;
        if (!sieve[p]) {
            primes[curr++] = p;
            sievize(p);
        }
    }
    unsigned long long wc = 30;
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

vector<unsigned> divisors(unsigned num) {
    vector<unsigned> div;
    auto limit = static_cast<unsigned int>(pow(num,0.5));
    for (auto d = 3u; d<=limit; ++d) {
        if (num%d==0)
            div.push_back(d);
    }
    return div;
}

inline bool isprime(unsigned num,unsigned lp) {
    if (num<2)
        return false;
    if (num<primes[lp-1]) {
        if (std::binary_search(primes,primes+lp,num))
            return true;
        else
            return false;
    }
    unsigned lim = pow(num,0.5)+1;
    for (auto i = 0u; i < lp and primes[i]<lim; ++i)
        if (num%primes[i]==0)
            return false;
    return true;
}

int main(void) {
    auto limit = cumulateprimes();
    unsigned long long sumnum = 1;
    for (auto p = 1u; primes[p]<50000000; ++p) {
        auto numb = 2*primes[p]-4;
        if (!isprime(numb+1,limit))
            continue;
        auto divs = divisors(numb);
        bool good = true;
        for (auto &d : divs) {
            if (!isprime(d+numb/d,limit)) {
                good = false;
                break;
            }
        }
        if (good)
            sumnum += numb;
    }
    cout << sumnum << endl;
}
