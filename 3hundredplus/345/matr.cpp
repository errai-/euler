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

#define DIM1 5
#define DIM2 15
#define DIM DIM2
#define LIM 1

vector<int> currmax(int m[DIM][DIM], bool allow[DIM][DIM]) {
    int rowmax = -1;
    int colmax = -1;
    int currmax = -1;
    for (int row = 0; row<DIM; ++row) {
    for (int col = 0; col<DIM; ++col) {
        if (!allow[row][col]) continue;
        if (m[row][col]>currmax) {
            currmax = m[row][col];
            rowmax = row;
            colmax = col;
        }
    }}
    return vector<int>({rowmax,colmax,currmax});
}

void elimrow(bool allow[DIM][DIM],int row) {
    for (int col = 0; col<DIM; ++col)
        allow[row][col] = false;
}

void elimcol(bool allow[DIM][DIM],int col) {
    for (int row = 0; row<DIM; ++row)
        allow[row][col] = false;
}

void probe(int m[DIM][DIM], bool allow[DIM][DIM], vector<int> &results,int currsum,int nesting,int repeat=0) {
    if (nesting==DIM) {
        results.push_back(currsum);
    } else {
        if (repeat<LIM) {
            vector<int> best = currmax(m,allow);
            bool newallow[DIM][DIM];
            std::copy(&allow[0][0],&allow[0][0]+DIM*DIM,&newallow[0][0]);
            elimrow(allow,best[0]);
            elimcol(allow,best[1]);
            probe(m,allow,results,currsum+best[2],nesting+1);
            newallow[best[0]][best[1]] = false;
            probe(m,newallow,results,currsum,nesting,repeat+1);
        } else {
            auto best = currmax(m,allow);
            elimrow(allow,best[0]);
            elimcol(allow,best[1]);
            probe(m,allow,results,currsum+best[2],nesting+1);
        }
    }
}

int main(void) {
    int m1[DIM1][DIM1] = {
          7,  53, 183, 439, 863,
        497, 383, 563,  79, 973,
        287,  63, 343, 169, 583,
        627, 343, 773, 959, 943,
        767, 473, 103, 699, 303};

    int m2[DIM2][DIM2] = {
          7,  53, 183, 439, 863, 497, 383, 563,  79, 973, 287,  63, 343, 169, 583,
        627, 343, 773, 959, 943, 767, 473, 103, 699, 303, 957, 703, 583, 639, 913,
        447, 283, 463,  29,  23, 487, 463, 993, 119, 883, 327, 493, 423, 159, 743,
        217, 623,   3, 399, 853, 407, 103, 983,  89, 463, 290, 516, 212, 462, 350,
        960, 376, 682, 962, 300, 780, 486, 502, 912, 800, 250, 346, 172, 812, 350,
        870, 456, 192, 162, 593, 473, 915,  45, 989, 873, 823, 965, 425, 329, 803,
        973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 673, 815, 165, 992, 326,
        322, 148, 972, 962, 286, 255, 941, 541, 265, 323, 925, 281, 601,  95, 973,
        445, 721,  11, 525, 473,  65, 511, 164, 138, 672,  18, 428, 154, 448, 848,
        414, 456, 310, 312, 798, 104, 566, 520, 302, 248, 694, 976, 430, 392, 198,
        184, 829, 373, 181, 631, 101, 969, 613, 840, 740, 778, 458, 284, 760, 390,
        821, 461, 843, 513,  17, 901, 711, 993, 293, 157, 274,  94, 192, 156, 574,
         34, 124,   4, 878, 450, 476, 712, 914, 838, 669, 875, 299, 823, 329, 699,
        815, 559, 813, 459, 522, 788, 168, 586, 966, 232, 308, 833, 251, 631, 107,
        813, 883, 451, 509, 615,  77, 281, 613, 459, 205, 380, 274, 302,  35, 805};

    bool allowed[DIM][DIM];
    for (int row = 0; row<DIM; ++row) {
    for (int col = 0; col<DIM; ++col) {
        allowed[row][col] = true;
    }}

    vector<int> results;
    probe(m2,allowed,results,0,0);

    auto best = std::max_element(results.begin(),results.end());
    cout << *best << endl;
}
