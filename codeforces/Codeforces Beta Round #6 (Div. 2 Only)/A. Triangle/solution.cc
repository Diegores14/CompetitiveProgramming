#include <bits/stdc++.h>
using namespace std;

int check( int a, int b, int c ) {
    if( a+b > c && a+c > b && c+b > a ) {
        return 2;
    }
    if( a+b >= c && a+c >= b && c+b >= a ) {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v[4];
    for( int i = 0; i < 4; i++ ) {
        cin >> v[i];
    }
    int ans = 0;
    for( int i = 0; i < 4; i++ ) {
        for( int j = i+1; j < 4; j++ ) {
            for( int k = j+1; k < 4; k++ ) {
                //cout << check( v[i], v[j], v[k] ) << '\n';
                ans = max( ans, check( v[i], v[j], v[k] ) );
            }
        }
    }
    if( ans ) {
        cout << ((ans==2)? "TRIANGLE" : "SEGMENT") << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}