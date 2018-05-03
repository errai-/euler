#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

typedef unsigned long long int ull;
typedef long long int ll;

ll factorial(ll num,ll p) {
    if (num==0) return 1;
    ll cumulate = 1;
    for (ll i = 2; i<=num; ++i) {
        cumulate *= (i%p);
        cumulate = cumulate%p;
    }
    return cumulate;
}

ll regularize(ll n,const ll p) {
    while (n<0) n += p;
    while (n>p) n -= p;
    return n;
}

ull testify(ll p) {
    return regularize(((((p*(p-2)+1)*(p-3)+1)*(p-4)+1)%p)*factorial(p-5,p),p);
}

ull modcalculus(const ll p) {
    ll alpha = (p-1)/2;
    bool minus = (alpha%3==0);
    ll beta = (minus ? (-alpha/3) : ((p+1)/6));
    bool even1 = (beta%2==0);
    ll gamma = ((even1) ? -beta/2 : ((minus) ? -(5*p+1)/12 : (5*p-1)/12));
    bool even2 = (gamma%2==0);
    ll delta = (even2 ? gamma/2 : (even1 ? (minus ? -(11*p+1)/24 : (11*p-1)/24) : (minus ? (7*p-1)/24 : -(7*p+1)/24)));
    ll triumph = alpha%p + beta%p + delta%p;
    return regularize(triumph%p,p);
}

int main(void) {
    std::ifstream myfile("../../primes_to3G.txt");
    vector<ull> primes;
    ull fager;
    while (myfile >> fager) {
        primes.push_back(fager);
    }

    int pridx = 2;
    ull cumulus = 0;
    while (primes[pridx]<100000000) {
        auto prim = primes[pridx++];
        ull tmp = modcalculus(prim);
        cumulus += tmp;
    }
    cout << cumulus << endl;
}
