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
typedef unsigned long int uli;
typedef long int li;

struct Vec {
    double x;
    double y;
    Vec() {
        x = 0;
        y = 0;
    }
    Vec(double x_, double y_) {
        x = x_;
        y = y_;
    }
    Vec& operator-=(const Vec& rhs){
      x -= rhs.x;
      y -= rhs.y;
      return *this;
    }
    Vec& operator+=(const Vec& rhs){
      x += rhs.x;
      y += rhs.y;
      return *this;
    }
    Vec& operator=(const Vec& rhs){
      x = rhs.x;
      y = rhs.y;
      return *this;
    }
    Vec tangens() {
        Vec tan;
        double norm = sqrtl(12*x*x+100);
        tan.x = y/norm;
        tan.y = -4*x/norm;
        return tan;
    }
    double dot(const Vec& rhs){
        return x*rhs.x+y*rhs.y;
    }
    void normalize() {
        double len = dot(*this);
        x /= sqrtl(len);
        y /= sqrtl(len);
    }
    Vec& operator*=(const double rhs){
      x *= rhs;
      y *= rhs;
      return *this;
    }
    void check() {
        cout << 4*x*x+y*y << endl;
    }
    bool pass() {
        return y>0 and fabs(x)<=0.01;
    }
    Vec crossing(const Vec& rhs) {
        double b = 2*(4*x*rhs.x+y*rhs.y);
        double a = (3*rhs.x*rhs.x+1);
        double n = fabs(b/a);
        Vec next = rhs;
        next *= n;
        next += *this;
        return next;
    }
    Vec reflect(const Vec& com) {
        Vec nw = tangens();
        nw.normalize();
        double coeff = nw.dot(com);
        nw *= (2*coeff);
        nw -= com;
        return nw;
    }
};

std::ostream& operator<<(std::ostream& os, const Vec& v) {
    os << v.x << ' ' << v.y;
    return os;
}

int main(void) {
    cout.precision(20);
    std::clock_t start = std::clock();
    ull counter = 0;
    Vec z0(0,10.1);
    //Vec z00(0.0071073169499658731332325523055715166265144944190979,9.9999898972040508482450604788027703762054443359375);
    Vec pt(1.4,-9.6);
    Vec dir = pt;
    dir -= z0;
    dir.normalize();
    //Vec tan = z1.tangens();
    //cout << z0 << endl;
    //cout << z1 << endl;
    //cout << z << endl;
    //Vec nxt = z00.crossing(z);
    //cout << "n" << nxt << endl;
    //cout << tan << endl;
    //z0.check();
    //z1.check();
    //cout << tan.dot(tan) << endl;
    while (!pt.pass()) {
        ++counter;
        Vec dirnext = pt.reflect(dir);
        dirnext.normalize();
        Vec ptnext = pt.crossing(dirnext);
        cout << ptnext << " " << dirnext << endl;
        dir = dirnext;
        pt = ptnext;
    }


    std::clock_t stop = std::clock();
    double dur = (stop - start) / static_cast<double> CLOCKS_PER_SEC;
    cout << dur << " " << counter << endl;
}
