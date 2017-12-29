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
    ull prev = 1;
    ull pruv = 1;
    for (ull n = 1; n<30; ++n) {
        ull now = prev + pruv;
        if (n%2==1)
            cout << (n+1)/2 << " " << now*prev << endl;
        pruv = prev;
        prev = now;
    }
}
