#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

typedef unsigned long long int ull;

bool ispow2(ull num) {
    double n = static_cast<double>(num);
    ull nsqr = static_cast<ull>(round(pow(n,0.5)));
    if (num==nsqr*nsqr)
        return true;
    return false;
}

int main(void) {
    ull Uplim = 1000000;
    double sqrlimit = floor((static_cast<double>(Uplim)+1)/2.0);
    vector<ull> sqrs;
    vector<ull> sqrs2;
    sqrs.push_back(0);
    for (ull sqr = 1; sqr <= sqrlimit; ++sqr) {
        ull tmp = sqr*sqr;
        sqrs.push_back(tmp);
        if (sqr%2==0)
            sqrs2.push_back(tmp);
    }

    map<ull,vector<string> > counts;
    map<ull,ull> uplims;
    for (ull sqr1i = 0; sqr1i < sqrs2.size(); ++sqr1i) {
        if (sqr1i%10000==0)
            cout << sqr1i << endl;
        ull lim2 = 2*sqr1i+2;
        for (ull sqr2i = 0; sqr2i < lim2; ++sqr2i) {
            ull n = sqrs2[sqr1i]-sqrs[sqr2i];
            if (n>=Uplim)
                continue;
            ull d = sqr1i+1;
            if (uplims.count(n)==0) {
                double uplimit = floor((static_cast<double>(n)+1)/4.0);
                ull ulim = static_cast<ull>(uplimit);
                uplims[n] = ulim;
                counts[n] = vector<string>();
            }
            if (d>uplims[n])
                continue;
            ull z = sqr2i;
            counts[n].push_back(std::to_string(z+3*d)+string(" - ")+std::to_string(z+2*d)+string(" - ")+std::to_string(z+d));
            if (d>z and z!=0)
                counts[n].push_back(std::to_string(-z+3*d)+string(" - ")+std::to_string(-z+2*d)+string(" - ")+std::to_string(-z+d));
        }
    }

    ull count = 0;
    for (auto & a : counts) {
        if (a.second.size()==10) {
            if (a.first<Uplim)
                count++;
        }
        cout << a.first << " " << a.second.size() << endl;
        //for (auto &b : a.second)
        //    cout << "  " << b << endl;
    }
    cout << endl << count << endl;
}
