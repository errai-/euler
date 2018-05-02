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

map<ull,ull> divisors(ull num,vector<ull> &prims) {
    map<ull,ull> results;
    ull pridx = 0;
    while (prims[pridx]<=sqrt(num)) {
        auto &curr = prims[pridx];
        while (num%curr==0) {
            results[curr] += 1;
            num /= curr;
        }
        pridx += 1;
    }
    if (num>1) results[num] = 1;
    return results;
}

ull minimal(ull no, ull reps) {
    ull creps = 0;
    for (ull nn = no; nn<reps*no; nn+=no) {
        ull tmpnn = nn;
        while (tmpnn%no==0) {
            tmpnn /= no;
            creps += 1;
            if (creps>=reps)
                return nn;
        }
    }
    return reps*no;
}

ull sfunc(map<ull,ull> &divs) {
    ull currmax = 0;
    for (auto &div : divs) {
        ull curr = minimal(div.first,div.second);
        if (curr>currmax) currmax = curr;
    }
    return currmax;
}

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<ull> primes;
    string fager;
    while (myfile >> fager) primes.push_back(std::stoi(fager));

    ull cumulator = 0;
    for (ull nro=2; nro<=100000000; ++nro) {
        auto divs = divisors(nro,primes);
        cumulator += sfunc(divs);
        if (nro%100000==0) cout << nro << " " << cumulator << endl;
    }
    cout << cumulator << endl;
}
