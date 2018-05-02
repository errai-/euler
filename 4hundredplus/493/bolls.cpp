#include <iostream>
#include <string>
#include <random>
#include <map>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using std::endl;
using std::cout;
using std::map;
using std::vector;
using std::max;
using std::min;

const double upstairs = 3628800;
const double factors[] =
{
1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0, 3628800.0
};

int factorial(int n,int many) {
    auto stop = max(many,n-many);
    auto left = min(many,n-many);
    int fact = 1;
    for (int i = stop+1; i <= n; ++i)
        fact *= i;
    for (int i = 2; i <= left; ++i)
        fact /= i;
    return fact;
}

double combos(int N, int lvl, int counter, vector<int> prevs, int prev, double div) {
    if (N==lvl) {
        prevs.push_back(20-counter);
        if (20-counter<1 or 20-counter>10)
            return 0.0;
        double factor = 1.0;

        vector<int> counts;
        auto pno = prevs[0];
        int reps = 1;
        cout << pno << endl;
        for (int i = 1; i<prevs.size(); ++i) {
            cout << prevs[i] << endl;
            if (pno==prevs[i])
                ++reps;
            else {
                pno = prevs[i];
                counts.push_back(reps);
                reps = 1;
            }
        }
        counts.push_back(reps);
        double currc = 7;
        int foktor = 1;
        for (auto & a : counts) {
            cout << " " << a << endl;
            foktor *= factorial(currc,a);
            currc -= a;
        }
        cout << "  " << foktor << endl;

        for (auto & a : prevs) {
            auto first = max(a,10-a);
            auto second = min(a,10-a);
            factor /= factors[first];
            factor *= upstairs;
            factor /= factors[second];
        }
        factor /= div;
        factor *= static_cast<double>(foktor);
        cout << factor << endl;
        return factor;
    } else {
        double cumulate = 0.0;
        int limit = min(10,(20-counter)/(N-lvl+1));
        for (int curr = prev; curr <= limit; ++curr) {
            vector<int> now(prevs);
            now.push_back(curr);
            auto c = combos(N,lvl+1,counter+curr,now,curr,div);
            cumulate += c;
        }
        return cumulate;
    }
}

int main() {
    cout << std::setprecision(20);
    double whole = 1, bole = 1;
    for (double i = 65.0; i <= 70.0; i+= 1.0)
        whole *= i;
    for (double i = 2.0; i <= 20.0; i+= 1.0)
        whole /= i;
    for (double i = 58.0; i < 65.0; i+= 1.0)
        whole *= i;
    cout << whole << endl;
    for (double i = 51.0; i < 58.0; i+= 1.0)
        bole *= i;
    cout << bole << endl;

    double probs[8] = {};
    for (int N = 2; N <= 7; ++N) { // Number of balls
        probs[N] = combos(N,1,0,vector<int>(),1,bole)/whole;
    }

    double sumprobs = 0.0, weighted = 0.0;
    for (auto i = 2u; i <= 7u; ++i) {
        cout << i << " " << probs[i] << " " << probs[i]*1.2*39620477651 << endl;
        sumprobs += probs[i];
        weighted += probs[i]*static_cast<double>(i);
    }
    cout << sumprobs << " " << weighted << endl;


    return 0;
}
