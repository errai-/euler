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
typedef long int li;

const uli LIM = 1000000000;
const uli check = 100;

struct Num {
    uli num;
    vector<li> counts;
    uli curridx;
    vector<uli> *divs;
    Num() {
        num = 1;
        counts.push_back(0);
        curridx = 0;
        divs = 0;
    }
    Num(const Num &no, uli pr = 0, bool cp = true) {
        curridx = no.curridx;
        num = no.num;
        counts = no.counts;
        if (no.divs!=0) {
            divs = no.divs;
            if (!cp) {
                if (pr==0) {
                    num *= divs->at(curridx);
                    counts[curridx]++;
                } else {
                    counts.push_back(0);
                    ++curridx;
                }
            }
        }
    }
};


int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<uli> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    vector<uli> divs;
    uli pridx = 0;
    while (primes[pridx]<=check) divs.push_back(primes[pridx++]);

    bool *left = new bool [LIM+1];
    for (uli i = 1; i<=LIM; ++i) left[i] = false;
    left[1] = true;

    for (auto &a : divs) cout << a << " ";
    cout << endl;
    vector<Num*> nums = {new Num()};
    nums.back()->divs = &divs;
    std::clock_t start = std::clock();
    uli place = 0;
    while (place<nums.size()) {
        auto &now = *nums[place++];
        if (now.num<=LIM) {
            left[now.num] = true;
            if (now.curridx<divs.size()-1) nums.push_back(new Num(now,1,false));
            nums.push_back(new Num(now,0,false));
        }
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    uli counter = 0;
    for (uli i = 1; i<=LIM; ++i) if (left[i]) { ++counter; }
    cout << dur << " " << counter << endl;
    delete left;
    for (auto &j : nums) delete j;
}
