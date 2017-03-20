// Code for PE problem 103. Note: the functions return true, if a conflict or erroneous case is found.

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cerr;

typedef vector<int> vec;

int amnt = 7;
int nums[] = {20,31,38,39,40,42,45};

bool combos(vec&, vec&, int);
bool equalizer(vec&, vec&, int, int);

inline int vec_sum(vec& summer) {
    return std::accumulate(summer.begin(), summer.end(), 0);
}

inline bool equal_loop(vec& first, vec& second, int allowed, int needed) {
    for (unsigned i = allowed; i <= second.size()-needed; ++i) {
        vec nfirst(first.begin(),first.end());
        nfirst.push_back(second[i]);
        vec nsecond;
        nsecond.reserve( second.size()-1 );
        nsecond.insert( nsecond.end() ,second.begin(), second.begin()+i );
        nsecond.insert( nsecond.end(), second.begin()+i+1, second.end() );
        if (equalizer(nfirst, nsecond, i, needed-1))
            return true;
    }
    return false;
}

inline bool equal_fin(vec& first, vec& second) {
    if (vec_sum(first)==vec_sum(second)) {
        cout << "First ";
        for (unsigned i = 0; i < first.size(); ++i)
            cout << first[i] << " ";
        cout << "Second ";
        for (unsigned i= 0; i < second.size(); ++i)
            cout << second[i] << " ";
        cout << endl;
        return true;
    } else
        return false;
}

bool equalizer(vec& first, vec& second, int allowed, int needed) {
    if (second.size() > first.size()) {
        return equal_loop(first, second, allowed, needed);
    } else if (second.size() < first.size()) {
        cerr << "Erroneous vector splitting" << endl;
    } else {
        return equal_fin(first, second);
    }
}

inline bool combo_loop(vec& current, vec& cumul, int left) {
    for (unsigned i = 0, N = current.size()-left+1; i < N; ++i) {
        vec pool(current.begin()+i+1,current.end());
        vec next_cumul(cumul.begin(),cumul.end());
        next_cumul.push_back(current[i]);
        if (combos(pool, next_cumul, left-1))
            return true;
    }
    return false;
}

inline bool combo_fin(vec& res) {
    vec first(res.begin(),res.begin()+1), second(res.begin()+1,res.end());
    return equalizer(first, second, 0, (second.size()-first.size())/2.0);
}

bool combos(vec& current, vec& cumul, int left) {
    if (left > 0) {
        return combo_loop(current, cumul, left);
    } else {
        return combo_fin(cumul);
    }
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

int main(void) {

    using Clock = std::chrono::high_resolution_clock;

    Clock::time_point start = Clock::now();

    vec handle(nums,nums+amnt);
    vec cumulate;

    bool failing = false;
    if (uniqueness(handle)) {
        cout << "Invalid sequence; duplicate elements." << endl;
        failing = true;
    } else if (trimmer(handle)) {
        cout << "Invalid sequence; sum is not greater when n is greater." << endl;
        failing = true;
    }

    for (unsigned i = 4, N = handle.size(); i <= N; i+=2) {
        if (combos(handle,cumulate,i)) {
            cout << "Invalid sequence; sums don't match." << endl;
            failing = true;
            break;
        }
    }

    if (!failing)
        cout << "Valid sequence." << endl;

    Clock::time_point stop = Clock::now();

    std::chrono::duration<double> span = std::chrono::duration_cast<std::chrono::duration<double>>(stop-start);

    cout << "Timing: " << span.count() << " s." << endl;

    return 0;
}
