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

bool ispow2(long double num) {
    //long double nsqr = round(bagel);
    long double nsqr = round(sqrtl(num));
    //long double nsqr = round(powl(num,0.5));
    if (num==nsqr*nsqr) {
        printf("%.0LF %.0LF\n",num,nsqr);
        return true;
    }
    return false;
}

int main(void) {
    for (long double n = 1; n<500000000.0; ++n) {
        long double sqr = 5*n*n+14*n+1;
        if (ispow2(sqr))
            printf("%.0LF\n",n);
    }
    //ull lim = 500000000;
    //ull turn = 0;
    //for (long double n=500000000.0; n<5000000000000.0; ++n) {
    //    long double vogel = n+0.2;
    //    long double bagel = sqrt(2)*(n+1.25);
    //    long double bgl = round(bagel);
    //    if (fabs(bagel-bgl)>0.0000001)
    //        continue;
    //    ull bg = static_cast<ull>(bgl)%lim;
    //    ull lo = static_cast<ull>(n)%lim;
    //    ull forst = 2*lo*lo+5*lo+1;
    //    ull sec = bg*bg;
    //    forst = forst%lim;
    //    sec = sec%lim;
    //    if (forst==sec) {
    //        printf("%.0LF %.10LF\n",n,bagel);
    //        if (turn%2==1)
    //            n*=9.423;
    //        else
    //            n*=3.604;
    //        turn += 1;
    //    }
    //}

}
