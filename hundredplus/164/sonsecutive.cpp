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

const ll LIM=9;
const ll REPEATS=20;

struct Num {
    ll curr;
    ll prev;
    ll iter;
    ll multi;
    Num(ll cr = 0) {
        curr = cr;
        prev = 0;
        iter = 1;
        multi = 1;
    }
    Num(const Num &sr, ll nxt = 0, bool cp = true) {
        if (cp) {
            curr = sr.curr;
            prev = sr.prev;
            iter = sr.iter;
        } else {
            curr = nxt;
            prev = sr.curr;
            iter = sr.iter+1;
        }
        multi = sr.multi;
    }
    ll highest() {
        return LIM-curr-prev;
    }
};


int main(void) {
    vector<Num*> nums;
    vector<Num*> nxtnums;
    for (ll n = 0; n<=9; ++n) {
        Num *jaa = new Num(n);
        nums.push_back(jaa);
    }
    std::clock_t start = std::clock();
    ll counter = 0;
    for (ll lvl = 1; lvl<=REPEATS; ++lvl) {
        while (nums.size()>0) {
            auto nn = nums.back();
            auto &now = *nn;
            nums.pop_back();
            if (lvl==REPEATS) {
                counter += now.multi;
                cout << now.curr << " " << now.prev << " " << now.multi << endl;
            } else {
                ll lolim = 0;
                if (lvl==REPEATS-1) lolim = 1;
                ll uplim = now.highest();
                ll prev = now.curr;
                for (ll curr = lolim; curr <= uplim; ++curr) {
                    bool found = false;
                    for (ll nxt = 0; nxt < nxtnums.size(); ++nxt) {
                        if (nxtnums[nxt]->curr==curr and nxtnums[nxt]->prev==prev) {
                            found = true;
                            nxtnums[nxt]->multi += now.multi;
                            break;
                        }
                    }
                    if (!found) nxtnums.push_back(new Num(now,curr,false));
                }
            }
            delete nn;
        }
        nums = nxtnums;
        nxtnums.clear();
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
    for (auto &j : nums) delete j;
}
