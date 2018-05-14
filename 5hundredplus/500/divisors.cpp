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

typedef unsigned long long int ull;
typedef long long int ll;

map<int,int> divisors(int num, const vector<ull> &prims) {
    map<int,int> divs;
    unsigned pridx = 0;
    int lim = sqrt(num);
    while (prims[pridx]<=lim) {
        auto &prim = prims[pridx++];
        if (num%prim==0) {
            num /= prim;
            int counter = 1;
            while (num%prim==0) {
                num /= prim;
                ++counter;
            }
            lim = sqrt(num);
            divs[prim] = counter;
        }
    }
    if (num>1) divs[num] = 1;
    return divs;
}

int numdivisors(const int num, const vector<ull> &prims, vector<string> &stuff) {
    auto divs = divisors(num,prims);
    int count = 1;
    for (auto &div : divs) {
        count *= (div.second+1);
        stuff.push_back( std::to_string(div.first) + "-" + std::to_string(div.second));
    }
    return count;
}

const ull GODEL = 500500507;

struct Order {
    double lognum;
    ull combos;
    ll idx;
    vector<int> *repeats;
    vector<ull> *prims;
    const Order *prev;
    ~Order() {
        //delete repeats;
    }
    Order() {
        lognum = log10(2);
        combos = 1;
        idx = -1;
        repeats = new vector<int>();
        repeats->push_back(1);
        prev = 0;
    }
    Order(const Order & ord, ll pridx) {
        combos = ord.combos;
        ++combos;
        prims = ord.prims;
        lognum = ord.lognum;
        idx = pridx;
        prev = &ord;
        ull prime = (*prims)[idx];
        if (idx < ord.cases()) {
            lognum += log10(prime)*powl(2,ord.first(idx));
        } else
            lognum += log10(prime);
        repeats = new vector<int>();
    }
    void prepare() const {
        if (prev) {
            *repeats = *prev->repeats;
            ll plats = repeats->size()-1;
            ull cumul = (*repeats)[plats];
            if (idx < cumul) {
                (*repeats)[plats] -= 1;
                repeats->push_back(1);
            } else {
                while (--plats >= 0) {
                    cumul += (*repeats)[plats];
                    if (idx < cumul) {
                        (*repeats)[plats] -= 1;
                        (*repeats)[plats+1] += 1;
                        break;
                    }
                }
                if (plats==-1) (*repeats)[0] += 1;
            }
        }
    }
    ull cases() const {
        ull cumul = 0;
        for (ull i = 0; i < repeats->size(); ++i)
            cumul += (*repeats)[i];
        return cumul;
    }
    ull first(ull idx) const {
        ull cumul = 0;
        ll plats = repeats->size();
        while (--plats >= 0) {
            cumul += (*repeats)[plats];
            if (idx < cumul) break;
        }
        return plats+1;
    }
    void destruction() const {
        ull cumulate = 1;
        ll plats = repeats->size();
        ull cumul = 0;
        ull exp = 0;
        for (ull idx = 0; idx<combos; ++idx) {
            if (idx >= cumul) {
                --plats;
                exp = plats + 1;
                cumul += (*repeats)[plats];
            }
            ull prime = prims->at(idx);
            ull tmp = 1;
            ull target = powl(2,exp)-1;
            for (ull i = 0; i < target; ++i) {
                tmp *= prime;
                tmp %= GODEL;
            }
            cumulate *= tmp;
            cumulate %= GODEL;
        }
        cout << "Suu: " << cumulate << endl;
    }
    bool operator<( const Order& other ) const
    {
        return lognum < other.lognum;
    }
};

#define LOGLIM 5000000

int main(void) {
    std::ifstream myfile("../../primes_to25M.txt");
    vector<ull> primes;
    ull fager;
    while (myfile >> fager) { primes.push_back(fager);}

    std::clock_t start = std::clock();
    set<Order> nexus;
    Order fugue;
    fugue.prims = &primes;
    nexus.insert(fugue);
    auto study = nexus.begin();
    while (study->lognum<LOGLIM) {
        ull limit = study->combos;
        study->prepare();
        auto stadi = study;
        ++stadi;
        while (stadi!=nexus.end()) {
            if (stadi->combos <= limit) {
                auto tmp = stadi;
                ++stadi;
                nexus.erase(tmp);
            } else {
                ++stadi;
            }
        }
        ull cumul = 0;
        nexus.insert(Order(*study,cumul));
        ll plats = study->repeats->size();
        while (--plats >= 0) {
            cumul += (*study->repeats)[plats];
            nexus.insert(Order(*study,cumul));
        }
        if (study->combos==500500) {
            cout << study->combos << " " << study->lognum << " " << study->repeats->size() << endl;
            //cout << study->combos << " " << study->lognum/log10(2) << " " << powl(10,study->lognum) << " " << study->repeats->size() << endl;
            for (ull i = 0; i<study->repeats->size(); ++i) cout << " " << (*study->repeats)[i];
            cout << endl;
            study->destruction();
            break;
        }

        ++study;
        //nexus.erase(study);
    }
    std::clock_t stahp = std::clock();
    //vector<int> vals({2,4,6,12,16,24,32,64,120,128});
    //int maxdivs = 0;
    //for (auto &i : vals) {
    //    vector<string> stuff;
    //    auto nums = numdivisors(i,primes,stuff);
    //    if (nums>maxdivs) {
    //        maxdivs = nums;
    //        cout << i << " " << nums;
    //        for (auto &a : stuff) cout << " " << a;
    //        cout << endl;
    //    }
    //}
    std::clock_t stop = std::clock();
    double dur1 = (stahp - start) / static_cast<double> CLOCKS_PER_SEC;
    double dur2 = (stop - stahp) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur1 << " " << dur2 << " " << nexus.size() << endl;
}
