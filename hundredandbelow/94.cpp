#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>

using std::cout;
using std::endl;

typedef unsigned long long sint;

sint triangles(sint two_side) {
    sint major = 3*two_side-1;
    major *= major;
    major = (major-4)/3;
    long double root_major = sqrtl(static_cast<long double>(major));

    sint minor = major+4*two_side;
    long double root_minor = sqrtl(static_cast<long double>(minor));

    sint result = 0;

    bool major_add = false, minor_add = false;
    if ( fabs( round(root_major) - root_major ) < 0.0000000001 ) {
        major = static_cast<sint>(root_major+0.5);
        sint side = two_side+1;
        if ( side%4==0 || (side%2==0&&major%2==0) || (major%4==0) ) {
            major_add = true;
        }
    }
    
    if ( fabs( round(root_minor) - root_minor ) < 0.0000000001 ) {
        minor = static_cast<sint>(root_minor+0.5);
        sint side = two_side-1;
        if ( side%4==0 || (side%2==0&&minor%2==0) || (minor%4==0) ) {
            minor_add = true;
        }
    }

    if ( major_add && minor_add ) {
        return 6*two_side;
    } else if ( major_add ) {
        return 3*two_side+1;
    } else if ( minor_add ) {
        return 3*two_side-1;
    }
    return 0;
}

int main(void) {
    sint result = 0;
    for ( sint i = 2; i <= 333333333; ++i ) {
        if ( i%1000000==0 ) cout << i << endl;
        result += triangles(i);
    }
    cout << result << endl;
}
