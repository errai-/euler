#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;

float operation( float no1, float no2, int operation ) {
    if ( operation==0 ) {
        return no1+no2;
    } else if ( operation==1 ) {
        return no1-no2;
    } else if ( operation==2 ) {
        return no1*no2;
    } else {
        return no1/no2;
    }
}

int validity( float result ) {
    if ( result < 0 ) return -1;

    float rounded = round( result );
    if ( fabs( rounded - result ) < 0.001 ) return static_cast<int>(result+0.5);
    return -1;
}

/* Operators: 0: +, 1: -, 2: *, 3: / */
void operating_types(set<int> &numbers, int *orders, float *permuter) {
    for (int op1 = 0; op1 < 4; ++op1) {
    for (int op2 = 0; op2 < 4; ++op2) {
    for (int op3 = 0; op3 < 4; ++op3) {
        int ops[] = {op1,op2,op3};
        float editor[] = {permuter[0],permuter[1],permuter[2],permuter[3]};

        editor[ orders[0] ] = operation( editor[ orders[0] ], editor[ orders[0]+1 ], ops[ orders[0] ] );
        for (std::size_t i = orders[0]+2; i < 4; ++i) {
            editor[i-1] = editor[i];
        }

        int second = orders[1] - ( (orders[1] > orders[0]) ? 1 : 0);
        editor[ second ] = operation( editor[ second ], editor[ second+1 ], ops[ orders[1] ] );
        if ( second==0 ) editor[1] = editor[2];

        editor[0] = operation( editor[0], editor[1], ops[ orders[2] ] );

        int reduction = validity( editor[0] );
        if ( reduction>0 ) numbers.insert( reduction );
    }
    }
    }
}

void operating_orders(set<int> &numbers, float *permuter) {
    int orders[] = {0,1,2};
    int editor[] = {0,0,0};
    do {
        operating_types(numbers, orders, permuter);
    } while ( std::next_permutation( orders, orders+3 ) );
}

int longest_consecution(const set<int> &numbers) {
    int prev = -1;
    int curr_range = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (prev==-1) {
            if (*it!=1) return 0;
            prev = *it;
            ++curr_range;
        } else if (*it == prev+1) {
            prev = *it;
            ++curr_range;
        } else {
            break;
        }
    }
    return curr_range;
}

int consecutives(float a, float b, float c, float d) {
    float permuter[] = {a,b,c,d};
    set<int> numbers;
    do {
        operating_orders( numbers, permuter );
    } while ( std::next_permutation( permuter, permuter+4 ) );

    return longest_consecution(numbers);
}

string digit_loop() {
    int most_consecutives = 0;
    vector<int> best_digits(4,0);
    for (int a =   0; a <  7; ++a) {
    for (int b = a+1; b <  8; ++b) {
    for (int c = b+1; c <  9; ++c) {
    for (int d = c+1; d < 10; ++d) {
        int tmp_consecutives = consecutives(a,b,c,d);
        if ( tmp_consecutives > most_consecutives ) {
            most_consecutives = tmp_consecutives;
            best_digits[0] = a; best_digits[1] = b;
            best_digits[2] = c; best_digits[3] = d;
        }
    }
    }
    }
    }
    string result = "";
    for (int i = 0; i < 4; ++i) {
        result += std::to_string( best_digits[i] );
    }
    return result;
}

int main(void) {
    cout << "Testing: this " << consecutives(1,2,3,4) << " should be 28." << endl;
    cout << digit_loop() << endl;
}
