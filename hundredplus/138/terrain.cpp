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
        long double sqr = 5*n*n+4*n+1;
        if (ispow2(sqr))
            printf("%.0LF\n",n);
    }
}
