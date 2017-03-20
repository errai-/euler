// Code for PE problem 105. Note: the functions return true, if a conflict or erroneous case is found.

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

bool combo_fill(vec&, vec&, unsigned, unsigned);
bool equal_fill(vec&, vec&, unsigned, unsigned&);

inline int vec_sum(vec& summer) {
    return std::accumulate(summer.begin(), summer.end(), 0);
}

inline bool equal_fin(vec& cumul, unsigned& ref_sum) {
    if (vec_sum(cumul)==ref_sum)
        return true;
    else
        return false;
}

inline bool equal_loop(vec& pool, vec& cumul, unsigned needed, unsigned& ref_sum) {
    for (unsigned i = 0, N = pool.size()-needed; i <= N; ++i) {
        vec next_pool(pool.begin()+i+1,pool.end());
        vec next_cumul(cumul.begin(),cumul.end());
        next_cumul.push_back(pool[i]);
        if (equal_fill(next_pool, next_cumul, needed-1, ref_sum))
            return true;
    }
    return false;
}

bool equal_fill(vec& pool, vec& cumul, unsigned needed, unsigned& ref_sum) {
    if (needed > 0) {
        return equal_loop(pool, cumul, needed, ref_sum);
    } else {
        return equal_fin(cumul, ref_sum);
    }
}

inline bool combo_fin(vec& pool, vec& cumul) {
    unsigned units = cumul.size();
    unsigned ref_sum = vec_sum(cumul);

    vec next_cumul;
    return equal_fill(pool,next_cumul,units,ref_sum);
}

inline bool combo_loop(vec& pool, vec& cumul, unsigned left, unsigned start) {
    for (unsigned i = start, N = pool.size()-left+1; i < N; ++i) {
        vec next_pool(pool.begin(),pool.end());
        next_pool.erase(next_pool.begin()+i);
        vec next_cumul(cumul.begin(),cumul.end());
        next_cumul.push_back(pool[i]);
        if (combo_fill(next_pool, next_cumul, left-1, i))
            return true;
    }
    return false;
}

bool combo_fill(vec& pool, vec& cumul, unsigned left, unsigned start) {
    if (left == 0) {
        return combo_fin(pool, cumul);
    } else {
        return combo_loop(pool, cumul, left, start);
    }
}

bool combos(vec& pool, unsigned nos) {
    for (unsigned i = 0, N = pool.size()-nos; i <= N; ++i) {
        vec next_pool(pool.begin()+i+1,pool.end());
        vec cumul;
        cumul.push_back(pool[i]);
        if (combo_fill(next_pool, cumul, nos/2-1, 0))
            return true;
    }
    return false;
}

bool trimmer(vec& all) {
    for (unsigned i = 1, N = (all.size()-1)/2.0; i <= N; ++i) {
        unsigned s1 = 0, s2 = 0;
        for (unsigned j = 0; j < i+1; ++j)
            s1 += all[j];
        for (unsigned j = all.size()-i; j < all.size(); ++j)
            s2 += all[j];
        if (s1 <= s2)
            return true;
    }
    return false;
}

bool uniqueness(vec& all) {
    for (unsigned i = 0, N = all.size()-1; i < N; ++i) {
        for (unsigned j = i+1; j < all.size(); ++j)
            if (all[i]==all[j])
                return true;
    }
    return false;
}

bool work_horse(vec& handle) {
    std::sort(handle.begin(),handle.end());

    if (uniqueness(handle)) {
        return false;
    } else if (trimmer(handle)) {
        return false;
    } else {
        for (unsigned i = 4, N = handle.size(); i <= N; i+=2) {
            if (combos(handle,i)) {
                return false;
            }
        }
    }
    return true;
}

vec comma_parse(string& line) {
    std::stringstream sline(line);
    vec numbers;
    for (string tmp_no; std::getline(sline, tmp_no, ','); numbers.push_back(std::stoi(tmp_no)) );
    return numbers;
}

int main(void) {

    using Clock = std::chrono::high_resolution_clock;

    Clock::time_point start = Clock::now();

    std::ifstream rfile("p105_sets.txt");
    if (!rfile.is_open())
        return 1;

    string tmp_line;
    unsigned counter = 0;
    while (std::getline(rfile,tmp_line)) {
        vec parsed = comma_parse(tmp_line);
        if (work_horse( parsed ))
            counter += vec_sum(parsed);
    }

    Clock::time_point stop = Clock::now();

    std::chrono::duration<double> span = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);

    cout << "Timing: " << span.count() << " s." << endl;
    cout << "Result: " << counter << endl;
    return 0;
}
