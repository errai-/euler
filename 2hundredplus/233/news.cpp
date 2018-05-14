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

const lll LIM    = 1000000;

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


vector<pair<lll,lll> > study(const vector<lll> &sqrs, const lll N, const bool even = true) {
    const ull loplace = (even ? N/2 : (N-1)/2);
    const auto loiter = sqrs.begin()+loplace;
    const lll lolim = sqrs[loplace];
    const lll ulim = 2*lolim;
    vector< pair<lll,lll> > res;

    ull place = loplace+1;
    lll counter = 0;
    while (sqrs[place]<=ulim) {
        auto &alpha = sqrs[place++];
        lll currsqr = ulim-alpha;
        auto finder = std::lower_bound(sqrs.begin(),sqrs.end(),currsqr);
        if (*finder==currsqr) {
            ++counter;
            lll xc = N/2-lll(finder-sqrs.begin());
            lll yc = N/2-lll(place-1);
            res.push_back(std::make_pair(xc,yc));
            //cout << xc << " " << yc << " " << N-2*xc << " " << N-2*yc << " " <<
            //cout << lolim << " " << currsqr << " " << N << " " << xc << " " << yc << " " << (N/2.0-xc)*(N/2.0-xc)+(N/2.0-yc)*(N/2.0-yc) << " " << double(lolim)/2 << endl;
        }
    }
    return res;
}

int main(void) {
    std::clock_t start = std::clock();
    lll counter = 0;
    vector<lll> esquares;
    vector<lll> osquares;
    for (lll i = 1; i<=2*LIM; i+=2)
        osquares.push_back(i*i);
    for (lll i = 0; i<=2*LIM; i+=2)
        esquares.push_back(i*i);
    for (lll N = 1; N<LIM; ++N) {
        auto s = study(((N%2==0) ? esquares : osquares),N);
        if (s.size()>30) {
            double radius = N*N/2.0;
            cout << N << " " << 2*s.size()+1 << ": " << endl;
            //for (auto &a : s) {
            //    double xdiff = (N/2.0-a.first);
            //    double ydiff = (N/2.0-a.second);
            //    cout << " " << a.first << " " << a.second << " " << (xdiff*xdiff+ydiff*ydiff)/radius << endl;
            //}
        }
    }
    auto suu13 = study(osquares,13);
    auto suu26 = study(esquares,26);
    cout << "13" << endl;
    for (auto &a : suu13) cout << " " << a.first << " " << a.second << endl;
    cout << "26" << endl;
    for (auto &a : suu26) cout << " " << a.first << " " << a.second << endl;
    cout << 8*study(osquares,41,false).size()+4 << endl;
    cout << 8*study(esquares,10000).size()+4 << endl;
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
}
