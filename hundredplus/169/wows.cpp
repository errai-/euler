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
    int combos;
    Num() { combos = 1; }
};

struct Hole {
    int pos;
    int stall;
    int mid;
    int sleep;
    int edge;
    Hole() {}
};

vector<Hole> holes(vector<int> &rng) {
    vector<Hole> hos;
    bool inhole = false;
    int count = 0;
    int start = 1;
    for (int i = rng.size()-1; i>=0; --i) {
        if (rng[i]==0) {
            if (!inhole) {
                if (i+1==rng.size() or rng[i+1]<=0) continue;
                inhole = true;
                count = 0;
                start = i+1;
            }
            ++count;
            if (i==0) {
                hos.push_back(Hole());
                hos.back().pos = start;
                if (rng[start]==1) {
                    hos.back().stall = 1;
                    hos.back().sleep = 0;
                } else {
                    hos.back().stall = 0;
                    hos.back().sleep = 1;
                }
                hos.back().edge = 0;
                hos.back().mid = count;
            }
        }  else {
            if (inhole) {
                inhole = false;
                hos.push_back(Hole());
                hos.back().pos = start;
                if (rng[start]==1) {
                    hos.back().stall = 1;
                    hos.back().sleep = 0;
                } else {
                    hos.back().stall = 0;
                    hos.back().sleep = 1;
                }
                if (rng[i]<0) hos.back().edge = 0;
                else hos.back().edge = 1;
                hos.back().mid = count - hos.back().edge;
            }
        }
    }
    return hos;
}

void deepen(vector<Num*> &res, const vector<Hole> &hols, int pos, vector<int> choices, int combos) {
    if (pos==hols.size()) {
        res.push_back(new Num());
        res.back()->ex = choices;
        res.back()->combos = combos;
    } else {
        auto &hol = hols[pos];
        if (hol.stall==1) {
            choices[hol.pos] = -1;
            deepen(res,hols,pos+1,choices,combos);
            choices[hol.pos] = 1;
        }
        choices[hol.pos] -= 1;
        for (int i = hol.pos-1; i>hol.pos-1-hol.mid; --i) choices[i] = 1;
        if (hol.mid>0) {
            choices[hol.pos-hol.mid-hol.edge] = -1;
            deepen(res,hols,pos+1,choices,combos*(hol.mid+hol.sleep));
        }
        if (hol.edge==1) {
            choices[hol.pos-hol.mid-1] = 2;
            deepen(res,hols,pos+1,choices,combos*(1+hol.sleep));
        }
    }
}

void exponenti(ll num,vector<int> &res) {
    while (num>0) {
        int now = log2(num);
        res[now] = 1;
        num -= powl(2,now);
    }
}

int main(void) {
    ull counter = 0;
    vector<Num*> res;
    // The number is too big: work with hands
    vector<int> st(84,0);
    ull stdd = 437976473752567808;
    st[83] = 1;
    st[78] = 1;
    st[74] = 1;
    st[72] = 1;
    st[71] = 1;
    st[68] = 1;
    st[66] = 1;
    st[64] = 1;
    st[60] = 1;
    exponenti(stdd,st);
    res.push_back(new Num());
    res.back()->ex = st;
    std::clock_t start = std::clock();
    int idx = 0;
    while (idx<res.size()) {
        auto &num = *res[idx++];
        auto &vec = num.ex;
        auto hols = holes(vec);
        if (hols.size()>0) {
            deepen(res,hols,0,vec,num.combos);
        } else {
            counter += num.combos;
        }
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
    for (auto &j : res) delete j;
}
