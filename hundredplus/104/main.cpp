#include <iostream>
#include <string>
#include <gmpxx.h>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::count;

typedef mpz_class il;

char nums[] = {'1','2','3','4','5','6','7','8','9'};

inline void fibo_next(il& first, il& second) {
    il tmp = first+second;
    second = first;
    first = tmp;
}

bool pan_last(string& cur) {
    string interest = cur.substr( cur.size()-9, 9);
    if ( count(interest.begin(), interest.end(),'0') > 0 )
        return false;

    for (unsigned i = 0; i < 9; ++i) {
        if ( count(interest.begin(), interest.end(),nums[i]) > 1 ) {
            return false;
        }
    }
    return true;
}

bool pan_first(string& cur) {
    string interest = cur.substr( 0, 9);
    if ( count(interest.begin(), interest.end(),'0') > 0 )
        return false;

    for (unsigned i = 0; i < 9; ++i) {
        if ( count(interest.begin(), interest.end(),nums[i]) > 1 ) {
            return false;
        }
    }
    return true;
}

int main(void) {

    il cur = 1;
    il pre = 1;

    string tmp_str = "";
    unsigned counter = 3;
    while (tmp_str.size() < 9) {
        fibo_next(cur,pre);
        tmp_str = cur.get_str();
        ++counter;
    }

    while (tmp_str.size() < 100000) {
        fibo_next(cur,pre);
        tmp_str = cur.get_str();
        if (pan_first(tmp_str))
            if (pan_last(tmp_str))
                break;
        ++counter;
    }
    cout << counter << " (" << tmp_str.size() << ")" << ": " << cur << endl;

    return 0;
}
