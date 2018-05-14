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

map<int,int> divisors(int num, const vector<ull> &prims) {
    map<int,int> divs;
    unsigned pridx = 0;
    int lim = sqrt(num);
    while (prims[pridx]<=lim) {
        auto &prim = prims[pridx++];
        if (num%prim==0) {
            num /= prim;
            int counter = 1;
            while (num%prim==0) {
                num /= prim;
                ++counter;
            }
            lim = sqrt(num);
            divs[prim] = counter;
        }
    }
    if (num>1) divs[num] = 1;
    return divs;
}

int numdivisors(const int num, const vector<ull> &prims) {
    auto divs = divisors(num,prims);
    int count = 1;
    for (auto &div : divs)
        count *= (div.second+1);
    return count;
}

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<ull> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    int counter = 0;
    std::clock_t start = std::clock();
    int prevs = numdivisors(2,primes);
    for (ull i = 3; i<10000000; ++i) {
        int nums = numdivisors(i,primes);
        if (prevs==nums) {
//            cout << i << " " << nums << endl;
            ++counter;
        }
        prevs = nums;
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
}
