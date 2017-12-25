#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;
using std::pow;

#define ARRAY (300000000)
#define UPLIM (3000000000)
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

//inline bool isprime(unsigned num) {
//    //if (num<2)
//    //    return false;
//    //if (num<primes.back()) {
//    //    if (std::binary_search(primes.begin(),primes.end(),num))
//    //        return true;
//    //    else
//    //        return false;
//    //}
//    unsigned lim = pow(num,0.5)+1;
//    for (auto i = 0u; i < primes.size() and primes[i]<lim; ++i)
//        if (num%primes[i]==0)
//            return false;
//    return true;
//}

void cumulateprimes() {
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
    for (auto p = 0u; p < curr; ++p)
        cout << primes[p] << endl;
    //cout << curr << " " << UPLIM << endl;
}

int main(void) {
    cumulateprimes();
}
