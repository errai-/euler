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

long double ispow2(long double num) {
    //long double nsqr = round(bagel);
    long double nsqr = round(sqrtl(num));
    //long double nsqr = round(powl(num,0.5));
    if (num==nsqr*nsqr) {
        //printf("%.0LF %.0LF\n",num,nsqr);
        return nsqr;
    }
    return 0;
}

int main(void) {
    vector<long double> goods = {5,29,169,985,5741,33461,195025,1136689,6625109,38613965,225058681};
    vector<long double> foods = {7,41,239,1393,8119,47321,275807,1607521,9369319,54608393,318281039};


    vector<ull> geeds;
    vector<ull> feeds;
    for (auto i = 0u; i<goods.size(); ++i) {
        ull jaa = static_cast<ull>(goods[i]);
        geeds.push_back(jaa*jaa-1);
        ull juu = static_cast<ull>(foods[i]);
        feeds.push_back(juu+1);
    }
    vector<ull> downs;
    map<ull,ull> ups;
    downs.push_back(3);
    downs.push_back(20);
    downs.push_back(119);
    downs.push_back(696);
    downs.push_back(4059);
    downs.push_back(23660);
    downs.push_back(137903);
    downs.push_back(803760);
    downs.push_back(4684659);
    downs.push_back(27304196);
    downs.push_back(159140519);
    for (auto &a : downs)
        ups[a] = 0;

    //for (unsigned i = 0; i < feeds.size(); ++i)
    //    printf("%.1LF %.1LF\n",geeds[i],feeds[i]);

    // A demonstration of division errors count and sums ispow2 should work but it does not.
    long double perlim = 100000000.0;
    long double uplim = ceil(perlim/3);
    ull count = 0;
    for (long double ad = 1; ad<=uplim; ++ad) {
        for (auto &dv : downs) {
            ull a = static_cast<ull>(ad);
            if (dv>a)
                continue;
            if (a%dv!=0)
                continue;
            long double bd = round(ad/static_cast<long double>(dv));
            bd += ad;
            long double sqr = ad*ad+bd*bd;
            //long double cd = ispow2(sqr);
            long double cd = sqrtl(sqr);
            //if (cd==0)
            //    continue;
            if (ad+bd+cd>perlim)
                continue;
            printf("%.0LF %.0LF %.0LF\n",ad,bd,cd);
            count++;
            ups[dv] += 1;
        }
    }
    cout << count << endl;

    ull sums = 0;
    for (auto &dv : downs) {
        cout << 100000000/dv << endl;
        cout << ups[dv] << endl;
        sums += 100000000/dv;
    }
    cout << sums << endl;
}
