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

bool isprime(const int n, const vector<int> &prims) {
    int lim = sqrt(n);
    int pridx = 0;
    while (prims[pridx]<=lim) {
        if (n%prims[pridx++]==0) return false;
    }
    return true;
}

string check(int n, const vector<int> &prims) {
    int lim = sqrt(n);
    int pridx = 0;
    vector<int> primlist;
    while (prims[pridx]<=lim) {
        auto prim = prims[pridx++];
        if (n%prim==0) {
            while (n%prim==0)
                n /= prim;
            primlist.push_back(prim);
            if (primlist.size()==2) {
                if (n!=1) return "";
            }
            lim = sqrt(n);
        }
    }
    if (n!=1) primlist.push_back(n);
    if (primlist.size()==2) {
        return string(std::to_string(primlist[0])+"-"+std::to_string(primlist[1]));
    }
    return "";
}

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<int> primes;
    string fager;
    while (myfile >> fager) primes.push_back(std::stoi(fager));

    map<string,int> maximals;
    for (int n = 6; n<=10000000; ++n) {
        if (n%10000==0) cout << n << endl;
        if (isprime(n,primes)) continue;
        string stuff = check(n,primes);
        if (stuff!="") maximals[stuff] = n;
    }
    ull cumulator = 0;
    for (auto &a : maximals) {
        cout << a.first << " " << a.second << endl;
        cumulator += a.second;
    }
    cout << cumulator << endl;
}
