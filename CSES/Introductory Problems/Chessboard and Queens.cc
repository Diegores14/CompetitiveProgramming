#include <bits/stdc++.h>
using namespace std;
string v[8];
 
bool check( vector< int > &positions ) {
    set< int > s1, s2;
    for( int i = 0; i < 8; i++ ) {
        s1.insert(i-positions[i]);
        s2.insert(i+positions[i]);
        if(v[i][positions[i]] == '*') return false;
    }
    return s1.size() == 8 && s2.size() == 8;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector< int > positions(8);
    for( int i = 0; i < 8; i++ ) {
        positions[i] = i;
    }
    for( int i = 0; i < 8; i++ ) {
        cin >> v[i];
    }
    long long ans = 0;
    do {
        ans += check(positions);
    } while( next_permutation(positions.begin(), positions.end()) );
    cout << ans << '\n';
    return 0;
}
