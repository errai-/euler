#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::set;
using std::vector;

int divisor_sum( int number ) {
    if ( number==1 ) return 1;
    int limit = static_cast<int>( sqrt(number)+0.5 );
    int sum = 1;
    for (int i = 2; i < limit; ++i) {
        if ( number%i==0 ) {
            sum += number/i;
            sum += i;
            if ( number>1000000 ) return -1;
        }
    }
    if ( number%limit==0 ) {
        if ( number/limit!=limit ) sum += number/limit;
        sum += limit;
        if ( number>1000000 ) return -1;
    }
    return sum;
}

void chain_len( set<int>& processed, int current, int& longest, int& smallest ) {
    vector<int> chain;
    chain.push_back( current );
    current = divisor_sum( current );
    
    int diff = 0;
    while( current > 0 ) {
        auto loc = std::find( chain.begin(), chain.end(), current ); 
        if (loc != chain.end()) {
            diff = loc-chain.begin();
            break;
        }
        chain.push_back( current );
        processed.insert( current );

        current = divisor_sum( current );
    }

    if ( current > 0 && chain.size()-diff > longest ) {
        smallest = *std::min_element( chain.begin()+diff, chain.end() );
        longest = chain.size()-diff;
    }
}

int main(void) {
    set<int> processed;
    int longest = 0, smallest = -4;
    chain_len( processed, 12496, longest, smallest );
    for (int i=2; i <= 1000000; ++i) {
        if ( processed.find(i) == processed.end() ) {
            chain_len( processed, i, longest, smallest );
        }
    }
    cout << "Longest chain " << longest << " with the smallest element " << smallest << endl;
}
