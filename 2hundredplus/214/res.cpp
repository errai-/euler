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

const ull LIM = 40000000;
const ull FOOLIM = 25;

vector<ull> divisors(ull num, const vector<ull> &prims) {
    vector<ull> divs;
    unsigned pridx = 0;
    int lim = sqrt(num);
    while (prims[pridx]<=lim) {
        auto &prim = prims[pridx++];
        if (num%prim==0) {
            while (num%prim==0) { num /= prim; }
            divs.push_back(prim);
        }
    }
    if (num>1) divs.push_back(num);
    return divs;
}

ull totient(ull curr, vector<ull> &primes) {
    auto divs = divisors(curr,primes);
    for (auto &div : divs) {
        curr /= div;
        curr *= (div-1);
    }
    return curr;
}

bool is25(ull curr, vector<ull> &primes, map<ull,ull> &chain) {
    ull steps = 1;
    while (curr!=1) {
        if (steps>FOOLIM) return false;
        if (chain.find(curr)==chain.end()) {
            ull tmpcurr = totient(curr,primes);
            chain[curr] = tmpcurr;
            curr = tmpcurr;
        } else {
            curr = chain[curr];
        }
        ++steps;
    }
    return (steps==FOOLIM);
}


int main(void) {
    std::ifstream myfile("../../primes_to100M.txt");
    vector<ull> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    ull counter = 0;
    map<ull,ull> chain;
    ull pridx = 0;
    std::clock_t start = std::clock();
    while (primes[pridx]<LIM) {
        auto &prim = primes[pridx++];
        if (is25(prim,primes,chain)) {counter += prim;}
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
}
