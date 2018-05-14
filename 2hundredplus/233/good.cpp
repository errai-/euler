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
using std::pair;

typedef __int128 lll;
typedef unsigned long long int ull;
typedef long long int ll;
typedef unsigned long int uli;


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

vector<pair<ull,ull> > divisors(ull num, const vector<ull> &prims) {
    vector<pair<ull,ull> > divs;
    unsigned pridx = 0;
    int lim = sqrt(num);
    while (prims[pridx]<=lim) {
        auto &prim = prims[pridx++];
        if (num%prim==0) {
            ull count = 1;
            num /= prim;
            while (num%prim==0) { num /= prim; count++; }
            divs.push_back(std::make_pair(prim,count));
        }
    }
    if (num>1) divs.push_back(std::make_pair(num,1));
    return divs;
}

void iterdivs(ull curridx, ull templ, const vector<pair<ull,ull>> &divs, vector<ull> &res) {
    if (curridx==divs.size()) {
        res.push_back(templ);
    } else if (divs[curridx].first==2) {
        iterdivs(curridx+1,templ,divs,res);
    } else {
        auto &now = divs[curridx++];
        for (ull expo = 0; expo<now.second; ++expo) {
            iterdivs(curridx,templ,divs,res);
            templ *= now.first;
        }
        iterdivs(curridx,templ,divs,res);
    }
}

vector<ull> dividers(ull num, const vector<ull> &prims) {
    const auto divs = divisors(num,prims);
    vector<ull> results;
    iterdivs(0,1,divs,results);
    return results;
}

ull goodcount(ull num, const vector<ull> &prims) {
    auto divi = dividers(num,prims);
    ull c1 = 0;
    ull c2 = 0;
    for (auto &d : divi) {
        int over = d%4;
        if (over==1) ++c1;
        else ++c2;
    }
    return c1-c2;
}

int main(void) {
    std::ifstream myfile("../../primes_to100M.txt");
    vector<ull> selprimes;
    vector<ull> multiprimes;
    ull numstore;
    while (myfile >> numstore) {
        if (numstore%4==1) {
            selprimes.push_back(numstore);
        } else {
            multiprimes.push_back(numstore);
        }
    }

    std::clock_t start = std::clock();
    ull lim1 = 0;
    ull NLIM = 100000000000;
    while ( powl(selprimes[lim1],3)*powl(selprimes[lim1+1],2)*selprimes[lim1+2]<=NLIM ) { ++lim1; }
    vector<ull> goodies;
    for (ull idx1 = 0; idx1<lim1; ++idx1) {
        const ull f1 = selprimes[idx1];
        const ull f2 = selprimes[idx1]*selprimes[idx1];
        const ull f3 = f1*f2;
        ull lim2 = idx1+1;
        ull COMPLIM = NLIM/f3;
        while ( powl(selprimes[lim2],2)*selprimes[lim2+1]<=COMPLIM ) { ++lim2; }
        for (ull idx2 = idx1+1; idx2<lim2; ++idx2) {
            ull s1 = selprimes[idx2];
            ull s2 = selprimes[idx2]*selprimes[idx2];
            ull s3 = s1*s2;
            ull lim3 = idx2+1;
            ull NEXTLIM = COMPLIM/s2;
            while ( selprimes[lim3]<=NEXTLIM ) { ++lim3; }
            for (ull idx3 = idx2+1; idx3<lim3; ++idx3) {
                ull t1 = selprimes[idx3];
                ull trial = f3*s2*t1;
                if (trial<=NLIM) goodies.push_back(trial);
                ull trial0 = s3*f2;
                if (trial0<NLIM) {
                    trial0 *= t1;
                    if (trial0<=NLIM) goodies.push_back(trial0);
                }
                ull t2 = selprimes[idx3]*selprimes[idx3];
                if (t2<NLIM) {
                    ull trial1 = f3*t2;
                    if (trial1<NLIM) {
                        trial1 *= s1;
                        if (trial1<=NLIM) goodies.push_back(trial1);
                        ull trial2 = s3*t2;
                        if (trial2<NLIM) {
                            trial2 *= f1;
                            if (trial2<=NLIM) goodies.push_back(trial2);
                        }
                    }
                    ull t3 = t1*t2;
                    if (t3<NLIM) {
                        ull trial3 = t3*f2;
                        if (trial3<NLIM) {
                            trial3 *= s1;
                            if (trial3<=NLIM) goodies.push_back(trial3);
                            ull trial4 = t3*s2;
                            if (trial4<NLIM) {
                                trial4 *= f1;
                                if (trial4<=NLIM) goodies.push_back(trial4);
                            }
                        }
                    }
                }
            }
        }
    }
    ull lim4 = 0;
    while ( powl(selprimes[lim4],7)*powl(selprimes[lim4+1],3)<=NLIM ) { ++lim4; }
    for (ull idx4 = 0; idx4<lim4; ++idx4) {
        ull lim5 = 0;
        ull f3 = selprimes[idx4]*selprimes[idx4]*selprimes[idx4];
        ull f7 = f3*f3*selprimes[idx4];
        ull COMPLIM = NLIM/f7;
        while ( powl(selprimes[lim5],3)<=COMPLIM ) { ++lim5; }
        for (ull idx5 = idx4+1; idx5<lim5; ++idx5) {
            ull s3 = selprimes[idx5]*selprimes[idx5]*selprimes[idx5];
            ull trial0 = f7*s3;
            goodies.push_back(trial0);
            ull s7 = s3*s3*selprimes[idx5];
            if (s7<=NLIM) {
                ull trial1 = s7*f3;
                if (trial1<=NLIM) goodies.push_back(trial1);
            }
        }
    }
    ull lim6 = 0;
    while ( powl(selprimes[lim6],10)*powl(selprimes[lim4+1],2)<=NLIM ) { ++lim6; }
    for (ull idx6 = 0; idx6<lim6; ++idx6) {
        ull lim7 = 0;
        ull f2 = selprimes[idx6]*selprimes[idx6];
        ull f4 = f2*f2;
        ull f8 = f4*f4;
        ull f10 = f8*f2;
        ull COMPLIM = NLIM/f10;
        while ( powl(selprimes[lim7],2)<=COMPLIM ) { ++lim7; }
        for (ull idx7 = idx6+1; idx7<lim7; ++idx7) {
            ull s2 = selprimes[idx7]*selprimes[idx7];
            ull trial0 = f10*s2;
            goodies.push_back(trial0);
            ull s4 = s2*s2;
            if (s4<NLIM) {
                ull s8 = s4*s4;
                if (s8<NLIM) {
                    ull s10 = s8*s2;
                    if (s10<=NLIM) {
                        ull trial1 = s10*f2;
                        if (trial1<=NLIM) goodies.push_back(trial1);
                    }
                }
            }
        }
    }

    ull CLIM = 278454; // 10**11 / 5**3 * 13**2 * 17
    vector<bool> usage(CLIM+1,false);
    usage[1] = true;
    vector<ull> coeffs(CLIM+1,0);
    for (auto &p : multiprimes) {
        if (p>CLIM) break;
        usage[p] = true;
    }
    for (ull i = 3; i<usage.size(); i+=2) {
        ull lim = sqrt(i);
        for (auto &p : multiprimes) {
            if (p>lim) break;
            if (i%p==0) {
                ull idx = i/p;
                usage[i] = usage[idx];
                break;
            }
        }
    }
    for (ull i = 2; i<usage.size(); i+=2) usage[i] = usage[i/2];
    ull cumsum = 0;
    for (ull i = 0; i<usage.size(); ++i) {
        if (usage[i]) {
            cumsum += i;
        }
        coeffs[i] = cumsum;
    }
    ull cumul = 0;
    for (ull i = 0; i<goodies.size(); ++i) {
        auto &g = goodies[i];
        if (g<=NLIM) {
            ull idx = NLIM/g;
            cumul += g*coeffs[idx];
        }
    }
    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << cumul << endl;
}
