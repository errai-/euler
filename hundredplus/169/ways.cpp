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

struct Num {
    vector<int> ex;
    int count1;
    int count2;
    int sum1;
    int sum2;
    Num() {
        count1 = 0;
        count2 = 0;
        sum1 = 0;
        sum2 = 0;
    }
    Num(const Num &sr, bool cp = true, int place=1) {
        ex = sr.ex;
        count1 = sr.count1;
        count2 = sr.count2;
        sum1 = sr.sum1;
        sum2 = sr.sum2;
        if (!cp) {
            if (ex[place]==1) {
                sum1 -= place;
                sum2 += place-1;
                count1 -= 1;
                count2 += 1;
            } else {
                sum1 += place;
                sum2 -= 1;
                count1 += 1;
            }
            ex[place-1] += 2;
            ex[place] -= 1;
        }
    }
    bool equal(const Num &sr, int place) {
        //cout << sr.count1 << " " << count1 << " " << sr.count2 << " " << count2 << endl;
        if (ex[place]-1!=sr.ex[place]) return false;
        if (ex[place-1]+2!=sr.ex[place-1]) return false;
        for (int i = 0; i<ex.size(); ++i) {
            if (i!=place and i!=place-1) {
                if (ex[i]!=sr.ex[i]) return false;
            }
        }
        return true;
    }
};

vector<int> exponenti(ll num) {
    int def = log2(num);
    vector<int> res(def+1,0);
    while (num>0) {
        int now = log2(num);
        res[now] = 1;
        num -= powl(2,now);
    }
    return res;
}

int main(void) {
    vector<Num*> res;
    res.push_back(new Num());
    int counter = 0;
    std::clock_t start = std::clock();
    ull st = powl(10,15);
    res.back()->ex = exponenti(st);
    int cnt = 0, dnt = 0;
    for (ull c = 0; c<res.back()->ex.size(); ++c) if (res.back()->ex[c]>0) {++cnt; dnt += res.back()->ex[c];}
    res.back()->count1 = cnt;
    res.back()->sum1 = dnt;
    int idx = 0;
    map<string,vector<Num*> > search;
    while (idx<res.size()) {
        auto &num = *res[idx++];
        ++counter;
        for (int i = 1; i<num.ex.size(); ++i) {
            if (num.ex[i]>0 and num.ex[i-1]==0) {
                bool found = false;
                int nxt1 = num.count1, nxt2 = num.count2, s1 = num.sum1, s2 = num.sum2;
                if (num.ex[i]==1) {
                    nxt1 -= 1;
                    nxt2 += 1;
                    s1 -= i;
                    s2 += i - 1;
                } else {
                    nxt1 += 1;
                    s1 += i;
                    s2 -= 1;
                }
                string tag = std::to_string(nxt1)+"-"+std::to_string(nxt2)+"-"+std::to_string(s1)+"-"+std::to_string(s2);
                auto &vec = search[tag];
                for (int jdx = 0; jdx<vec.size(); ++jdx) {
                    if (idx==jdx) continue;
                    auto &nam = *vec[jdx];
                    if (num.equal(nam,i)) {
                        found = true;
                        cout << "Hahaa!" << endl;
                        break;
                    }
                }
                if (!found) {
                    res.push_back(new Num(num,false,i));
                    vec.push_back(res.back());
                    cout << idx << " " << i << " " << res.size() << " " << vec.size() << endl;
                    for (auto &a : num.ex) cout << " " << a;
                    cout << endl;
                }
            }
        }
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
}
