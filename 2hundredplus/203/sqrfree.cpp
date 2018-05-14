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

bool sqrs(uli num, const vector<uli> &prims) {
    unsigned pridx = 0;
    int lim = sqrt(num);
    while (prims[pridx]<=lim) {
        auto &prim = prims[pridx++];
        if (num%prim==0) {
            num/=prim;
            if (num%prim==0) return false;
            while (num%prim==0) { num /= prim; }
        }
    }
    return true;
}

vector<uli> pascalize(vector<uli> &prev, bool odd, vector<uli> &nums) {
    vector<uli> news = {1};
    for (uli i = 1; i<prev.size(); ++i) {
        news.push_back(prev[i]+prev[i-1]);
        auto place = std::lower_bound(nums.begin(),nums.end(),news.back());
        if (*place != news.back()) nums.insert(place, news.back());
    }
    if (odd) news.push_back(2*prev.back());
    auto place = std::lower_bound(nums.begin(),nums.end(),news.back());
    if (*place != news.back()) nums.insert(place, news.back());
    return news;
}

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<uli> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    vector< vector<uli> > pscl;
    vector<uli> nums = {1};
    pscl.push_back(vector<uli>({1}));
    std::clock_t start = std::clock();
    for (uli row = 2; row<=51; ++row) {
        auto news = pascalize(pscl.back(),row%2==1,nums);
        cout << row << "  ";
        for (auto &a : news) cout << a << " ";
        cout << endl;
        pscl.push_back(news);
    }
    uli counter = 0;
    for (auto &n : nums) if(sqrs(n,primes)) counter += n;

    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << " " << nums.size() << endl;
}
