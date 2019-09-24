#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
ii G[21];
int n, m, a, b;
int v[7];

int cal() {
    //cout << "Debug\n";
    set< ii > s;
    for( int i = 0; i < m; i++ ) {
        a = v[G[i].first];
        b = v[G[i].second];
        if( a > b ) {
            swap(a, b);
        }
        //cout << a << ' ' << b << '\n';
        s.insert( ii(a, b) );
    }
    //cout << s.size() << '\n';
    return s.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for( int i = 0; i < m; i++ ) {
        cin >> a >> b; a--; b--;
        if( a > b ) swap( a, b );
        G[i] = ii(a, b);
    } 
    int ans  = 0;
    if( n == 7 ) {
        for( int i = 1; i < 7; i++) {
            for( int j = 0; j < 7; j++ ) {
                if( j >= i ) {
                    v[j] = j-1;
                } else {
                    v[j] = j;
                }
            }
            do {
                ans = max(ans, cal() );
            } while( next_permutation(v, v+n) );
        }
    } else {
        for( int i = 0; i < n; i++ ) {
            v[i] = i;
        }
        do {
            ans = max(ans, cal() );
        } while( next_permutation(v, v+n) );
    }
    cout << ans << '\n';
    return 0;
}