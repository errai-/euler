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
using std::pair;

typedef __int128 lll;
typedef unsigned long long int ull;
typedef long long int ll;
typedef unsigned long int uli;

const lll LIM    = 10000;

std::ostream& operator<<(std::ostream& os, const __int128 i) noexcept
{
  std::ostream::sentry s(os);
  if (s) {
    unsigned __int128 tmp = i < 0 ? -i : i;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (i < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (os.rdbuf()->sputn(d, len) != len) {
      os.setstate(std::ios_base::badbit);
    }
  }
  return os;
}

vector<pair<lll,lll> > divisors(lll num, const vector<lll> &prims) {
    vector<pair<lll,lll> > divs;
    unsigned pridx = 0;
    int lim = sqrt(num);
    while (prims[pridx]<=lim) {
        auto &prim = prims[pridx++];
        if (num%prim==0) {
            lll count = 1;
            num /= prim;
            while (num%prim==0) { num /= prim; count++; }
            divs.push_back(std::make_pair(prim,count));
        }
    }
    if (num>1) divs.push_back(std::make_pair(num,1));
    return divs;
}

void iterdivs(lll curridx, lll templ, const vector<pair<lll,lll>> &divs, vector<lll> &res) {
    if (curridx==divs.size()) {
        res.push_back(templ);
    } else if (divs[curridx].first==2) {
        iterdivs(curridx+1,templ,divs,res);
    } else {
        auto &now = divs[curridx++];
        for (lll expo = 0; expo<now.second; ++expo) {
            iterdivs(curridx,templ,divs,res);
            templ *= now.first;
        }
        iterdivs(curridx,templ,divs,res);
    }
}

vector<lll> dividers(lll num, const vector<lll> &prims) {
    const auto divs = divisors(num,prims);
    vector<lll> results;
    iterdivs(0,1,divs,results);
    return results;
}

lll goodcount(lll num, const vector<lll> &prims) {
    auto divi = dividers(num,prims);
    lll c1 = 0;
    lll c2 = 0;
    for (auto &d : divi) {
        //cout << " " << d << endl;
        int over = d%4;
        if (over==1) ++c1;
        else ++c2;
    }
    return 4*(c1-c2);
}

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<lll> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    std::clock_t start = std::clock();
    for (lll N= 2; N<LIM; ++N) {
        if (N%2==0)
            cout << N << " " << goodcount(N*N/2,primes)<< endl;
        else {
            cout << N << " " << goodcount(2*N*N,primes)<< endl;
        }
    }
    lll se = 10000;
    cout << goodcount(se*se/2,primes) << endl;
    cout << goodcount(2*13*13,primes) << " " << goodcount(2*26*26,primes) << endl;
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << endl;
}
