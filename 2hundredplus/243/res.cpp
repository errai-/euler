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

const ull LIM = 10000000000;

vector<uli> divisors(uli num, const vector<uli> &prims) {
    vector<uli> divs;
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

uli erasthothenes(uli num, bool *nums, const vector<uli> &divs) {
    for (uli i = 1; i<num; ++i) nums[i] = true;
    for (auto &div : divs) {
        for (uli i = div; i < num; i += div) {
            nums[i] = false;
        }
    }
    uli counter = 0;
    for (uli i = 1; i<num; ++i) if (nums[i]) { ++counter; }
    return counter;
}

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<uli> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    //vector<uli> numms;
    //numms.push_back(2);
    //for (uli pri = 1; pri < 20; ++pri) numms.push_back(numms.back()*primes[pri]);
    bool *left = new bool [LIM];
    std::clock_t start = std::clock();
    double limit = 15499.0/94744;
    double minimum = 1;
    uli bastion = 1;
    cout.precision(20);
    uli upper = 10223092870;
    uli jump = 223092870;
    //for (uli &i : numms) {
    uli count = 0;
    for (uli i = std::max(int(jump),2); i<=upper; i += jump) {
        auto divs = divisors(i,primes);
        uli goodness = erasthothenes(i, left, divs);
        double mini = static_cast<double>(goodness)/(i-1);
        if (mini<minimum) { minimum = mini; bastion = i; }
        if (mini<limit) cout << "HOX!!" << endl;
        cout << count++ << " " << i << " " << goodness << " " << mini << " " << minimum << " " << limit << " " << bastion << endl;
    }
    cout << minimum << " " << bastion << endl;
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << endl;
    delete left;
}
