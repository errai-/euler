#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

typedef unsigned long long int ull;

bool ispow2(long double num,long double bagel) {
    long double nsqr = round(bagel);
    //long double nsqr = round(sqrtl(num));
    //long double nsqr = round(powl(num,0.5));
    if (num==nsqr*nsqr) {
        printf("%.0LF %.0LF\n",num,nsqr);
        return true;
    }
    return false;
}

int main(void) {
    for (long double n = 1; n<507544128.0; ++n) {
        long double sqr = 5*n*n+2*n+1;
        long double vogel = n+0.2;
        long double bagel = sqrt(5)*(vogel+2.0/(25*vogel));
        if (ispow2(sqr,bagel))
            printf("%.0LF %.10LF\n",n,bagel);
    }

    for (long double n=507544128.0; n<5000000000000.0; ++n) {
        ull lim = 500000000;
        long double vogel = n+0.2;
        long double bagel = sqrt(5)*(vogel+2.0/(25*vogel));
        long double bgl = round(bagel);
        if (fabs(bagel-bgl)>0.00001)
            continue;
        ull bg = static_cast<ull>(bgl)%lim;
        ull lo = static_cast<ull>(n)%lim;
        ull forst = 5*lo*lo+2*lo+1;
        ull sec = bg*bg;
        forst = forst%lim;
        sec = sec%lim;
        if (forst==sec) {
            printf("%.0LF %.10LF\n",n,bagel);
        }
    }
}
