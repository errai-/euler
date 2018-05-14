#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <fstream>
#include <random>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

typedef unsigned long long int ull;


int main(void) {
    map<int,double> pways;
    map<int,double> cways;

    double ptot = 0;
    for (int p1=1; p1<=4; ++p1) {
    for (int p2=1; p2<=4; ++p2) {
    for (int p3=1; p3<=4; ++p3) {
    for (int p4=1; p4<=4; ++p4) {
    for (int p5=1; p5<=4; ++p5) {
    for (int p6=1; p6<=4; ++p6) {
    for (int p7=1; p7<=4; ++p7) {
    for (int p8=1; p8<=4; ++p8) {
    for (int p9=1; p9<=4; ++p9) {
        pways[p1+p2+p3+p4+p5+p6+p7+p8+p9] += 1.0;
        ptot += 1.0;
    }}}}}}}}}

    double ctot = 0;
    for (int c1=1; c1<=6; ++c1) {
    for (int c2=1; c2<=6; ++c2) {
    for (int c3=1; c3<=6; ++c3) {
    for (int c4=1; c4<=6; ++c4) {
    for (int c5=1; c5<=6; ++c5) {
    for (int c6=1; c6<=6; ++c6) {
        cways[c1+c2+c3+c4+c5+c6] += 1.0;
        ctot += 1.0;
    }}}}}}

    cout << "Peter:" << endl;
    for (auto &p : pways) {
        p.second /= ptot;
        cout << p.first << " " << p.second << endl;
    }
    cout << "Colin:" << endl;
    for (auto &c : cways) {
        c.second /= ctot;
        cout << c.first << " " << c.second << endl;
    }
    double prob = 0.0, probtot = 0.0;
    for (auto &p : pways) {
        for (auto &c : cways) {
            if (p.first>c.first) {
                prob += p.second*c.second;
            }
            probtot += p.second*c.second;
        }
    }
    cout << std::fixed << std::setprecision(9);
    cout << prob << " " << probtot << endl;
}
