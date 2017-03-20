// Code for PE problem 106. Note: the functions return true, if a conflict or erroneous case is found.

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cerr;

typedef vector<int> vec;

unsigned combo_fill(vec&, vec&, unsigned, unsigned);
unsigned equal_fill(vec&, vec&, vec&, unsigned);

inline unsigned equal_fin(vec& cumul1, vec& cumul2) {
    for ( unsigned i = 0; i < cumul1.size(); ++i) {
        if ( cumul1[i] > cumul2[i] )
            return 1;
    }
    //cout << endl << "First: ";
    //for ( auto v : cumul1 )
    //    cout << v << " ";
    //cout << endl << "Second: ";
    //for ( auto v : cumul2 )
    //    cout << v << " ";
    return 0;
}

inline unsigned equal_loop(vec& pool, vec& cumul1, vec& cumul2, unsigned needed) {
    unsigned cumulator = 0;

    for (unsigned i = 0, N = pool.size()-needed; i <= N; ++i) {
        vec next_pool(pool.begin()+i+1,pool.end());
        vec next_cumul(cumul2.begin(),cumul2.end());
        next_cumul.push_back(pool[i]);
        cumulator += equal_fill(next_pool, cumul1, next_cumul, needed-1);
    }
    return cumulator;
}

unsigned equal_fill(vec& pool, vec& cumul1, vec& cumul2, unsigned needed) {
    if (needed > 0) {
        return equal_loop(pool, cumul1, cumul2, needed);
    } else {
        return equal_fin(cumul1,cumul2);
    }
}

inline unsigned combo_fin(vec& pool, vec& cumul) {
    unsigned units = cumul.size();

    vec next_cumul;
    return equal_fill(pool,cumul,next_cumul,units);
}

inline unsigned combo_loop(vec& pool, vec& cumul, unsigned left, unsigned start) {
    unsigned cumulator = 0;

    for (unsigned i = start, N = pool.size()-left+1; i < N; ++i) {
        vec next_pool(pool.begin(),pool.end());
        next_pool.erase(next_pool.begin()+i);
        vec next_cumul(cumul.begin(),cumul.end());
        next_cumul.push_back(pool[i]);
        cumulator += combo_fill(next_pool, next_cumul, left-1, i);
    }

    return cumulator;
}

unsigned combo_fill(vec& pool, vec& cumul, unsigned left, unsigned start) {
    if (left == 0) {
        return combo_fin(pool, cumul);
    } else {
        return combo_loop(pool, cumul, left, start);
    }
}

unsigned combos(vec& pool, unsigned nos) {
    unsigned cumulator = 0;

    for (unsigned i = 0, N = pool.size()-nos; i <= N; ++i) {
        vec next_pool(pool.begin()+i+1,pool.end());
        vec cumul;
        cumul.push_back(pool[i]);
        cumulator += combo_fill(next_pool, cumul, nos/2-1, 0);
    }

    return cumulator;
}

unsigned work_horse(vec& handle) {
    unsigned cumulator = 0;

    for (unsigned i = 4, N = handle.size(); i <= N; i+=2)
        cumulator += combos(handle,i);

    return cumulator;
}

int main(void) {

    using Clock = std::chrono::high_resolution_clock;

    Clock::time_point start = Clock::now();

    vector<int> begin;

    for (int i = 1; i <= 12; ++i) {
        begin.push_back(i);
    }

    unsigned counter = work_horse(begin);

    Clock::time_point stop = Clock::now();

    std::chrono::duration<double> span = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);

    cout << "Timing: " << span.count() << " s." << endl;
    cout << "Result: " << counter << endl;
    return 0;
}
