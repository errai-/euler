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

typedef __int128 lll;
typedef unsigned long long int ull;
typedef long long int ll;
typedef unsigned long int uli;

const lll LIM    = 100000;
const lll SQRLIM = 2*LIM;

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


lll study(vector<lll> &sqrs, lll N) {
    lll lolim = N*N;
    lll ulim = 2*lolim;
    auto place = std::upper_bound(sqrs.begin(),sqrs.end(),lolim);
    lll counter = 0;
    while (*place<=ulim) {
        lll currsqr = ulim-*place;
        auto finder = std::lower_bound(sqrs.begin(),sqrs.end(),currsqr);
        if (*finder==currsqr) {
            ++counter;
            //lll xc = N/2-lll(finder-sqrs.begin());
            //lll yc = N/2-lll(place-sqrs.begin());
            //cout << xc << " " << yc << " " << N-2*xc << " " << N-2*yc << " " <<
            //cout << lolim << " " << currsqr << " " << N << " " << xc << " " << yc << " " << (N/2.0-xc)*(N/2.0-xc)+(N/2.0-yc)*(N/2.0-yc) << " " << double(lolim)/2 << endl;
        }
        ++place;
    }
    return 8*counter+4;
}

int main(void) {
    std::clock_t start = std::clock();
    lll counter = 0;
    vector<lll> esquares;
    vector<lll> osquares;
    for (lll i = 1; i<=LIM; i+=2)
        osquares.push_back(i*i);
    for (lll i = 0; i<=SQRLIM; i+=2)
        esquares.push_back(i*i);
    cout << study(esquares,10000) << endl;
    cout << study(osquares,41) << endl;
    for (lll i = 0; i<LIM; i+=2) {
        lll s = study(esquares,i);
        if (s>100) cout << i << " " << s << endl;
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
}
