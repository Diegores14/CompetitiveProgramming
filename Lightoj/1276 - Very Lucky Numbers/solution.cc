#include <bits/stdc++.h>
using namespace std;
const long long limit = 1e12;
int sz = 2046;
vector< long long > v;

void precal( long long sum = 0) {
    if( sum*10+4 < limit) {
        v.push_back( sum*10+4 );
        precal( sum*10+4 );
    }
    if( sum*10+7 < limit ) {
        v.push_back( sum*10+7 );
        precal( sum*10+7 );
    }
}

/* long long 10^19
10^12 * 10^12 = 10^24
mul  <= limit/v[i] */

void precal1( int idx = 0, long long mul = 1 ) {
    //cout << mul << '\n';
    if( mul != 1 && mul != 0 )
        v.push_back( mul );
    for( int i = idx; i < sz; i++ ) {
        if( mul <= limit/v[i] ) {
            precal1( i, mul*v[i] );
        } else break;
    }
}

long long bs( long long x ) {
    int l = -1, r = v.size();
    while( r-l != 1 ) {
        long long mid = (l+r)>>1;
        if( x < v[mid]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    int t;
    precal();
    sz = v.size();
    sort( v.begin(), v.end() );
    precal1();
    sort( v.begin(), v.end() );
    v.erase(unique( v.begin() , v.end() ) , v.end() );
    long long a, b;
    scanf("%d", &t);
    for( int cases = 1; cases <= t; cases++ ) {
        scanf("%lld %lld", &a, &b);
        int aa = lower_bound( v.begin() , v.end() , a ) - v.begin();
        int bb = upper_bound( v.begin() , v.end() , b ) - v.begin();
        printf("Case %d: %d\n", cases, bb-aa );
    }
    return 0;
}