#include <bits/stdc++.h>
using namespace std;
// for this problem you hace use catalan numbers
long long a, b;
const int limit = 1e5, mod = 1e8 + 7, tam = 2e6+5;
const long long limit2 = 1e10;
vector< long long > v;
int fact[2][tam];

long long exponentation( long long b, long long e ) {
    long long ans = 1;
    while( e ) {
        if( e&1 ) {
            ans = (ans * b)%mod;
        }
        b = (b*b)%mod;
        e >>= 1;
    }
    return ans;
}

void preCal() {
    for( int i = 2; i <= limit; i++ ) {
        long long temp = 1LL*i*i;
        while( temp <= limit2 ) {
            v.push_back( temp );
            temp *= i;
        }
    }
    v.push_back(0);
    int pos = 1;
    sort( v.begin(), v.end() );
    for( int i = 1; i < v.size() ; i++ ) {
        //cout << v[i] << '\n';
        if( v[i] != v[i-1] ) {
            v[pos++] = v[i];
        }
    }
    v.resize(pos);
    fact[0][0] = fact[1][0] = 1;
    for( int i = 1; i <= tam; i++ ) {
        fact[0][i] = (1LL*fact[0][i-1]*i)%mod;
        fact[1][i] = exponentation( fact[0][i], mod-2 );
    }
}

int bs( long long x) {
    int l = 0, r = v.size();
    while( r-l != 1 ) {
        int mid = (l+r)/2;
        if( v[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

long long catalan( int n ) {
    return ( ((1LL*fact[0][2*n]*fact[1][n])%mod) * fact[1][n+1] )%mod;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    preCal();
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> a >> b;
        int n = bs(b+1) - bs(a);
        cout << "Case " << cases << ": ";
        if( n ) {
            cout << catalan(n) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}