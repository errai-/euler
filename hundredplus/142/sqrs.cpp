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

ull ispow2(long double num) {
    long double nsqr = round(sqrtl(num));
    if (num==nsqr*nsqr) {
        //printf("%.0LF %.0LF\n",num,nsqr);
        return (ull) num;
    }
    return 0;
}

int main(void) {
    ull ulim = 1000;

    for (ull aidx = 4; aidx<ulim; ++aidx) {
        ull a = aidx*aidx;
        ull lolimb = sqrtl((a+1)/2);
        for (ull bidx = lolimb; bidx<aidx; ++bidx) {
            ull b = bidx*bidx;
            ull pows = ispow2(a-b);
            if (pows>0) {
                ull lolimc = sqrtl(pows);
                for (ull cidx = lolimc; cidx<bidx; ++cidx) {
                    ull c = cidx*cidx;
                    if (ispow2(b-c)) {
                        if (ispow2(a-c)) {
                            ull juu = a+b+c;
                            cout << a << " " << b << " " << c << " " << juu/2 << endl;
                            if (juu%2==0)
                                return 1;
                        }
                    }
                }
            }
        }
    }
}
