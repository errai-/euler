#include "Next.h"
#include <iomanip>

int main(void) {
    vector<double> values;
    for ( int i = 1; i < 12; ++i )
        values.push_back( Truth(i) );
    // The first bop value is trivially 1
    ulong bop_cumulator = 1;
    bop_cumulator += BOP(values.begin(),values.begin()+2);
    cout << std::setprecision(15);
    double cumul = 0;
    for ( unsigned i = 1; i < 11; ++i ) {
        double coming = round(BOP(values.begin(),values.begin()+i));
        if ( coming != values[i] )
            cumul += coming;
    }
    cout << cumul << endl;
}
