#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+3;
int n, q, v[tam];

int bs( int x, int i )  {
    int l = i-1, r = n+1;
    while( r-l != 1 ) {
        int mid = (l+r)>>1;
        if( v[mid] <= x) {
            l = mid; 
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, k;
    cin >> t;
    while( t-- ) {
        unordered_map< int, int > m;
        cin >> n >> q;
        v[0] = 0;
        m[0]++;
        for( int i = 1; i <= n; i++ ) {
            cin >> v[i];
            v[i] += v[i-1];
            m[v[i]]++;
        }
        while( q-- ) {
            long long ans = 0;
            cin >> k;
            for( int i = 0; i <= n; i++ ) {
                if( m.count(v[i]+k) )
                    ans += m[v[i]+k];
                /* int temp = k - v[i] + v[i-1] ;
                if( temp >= 0 ) {
                    ans += bs(v[i] + temp, i)bs(v[i] + temp - 1, i);
                }*/
            }
            cout << ans << (q? ' ' : '\n');
        }
    } 
    return 0;
}