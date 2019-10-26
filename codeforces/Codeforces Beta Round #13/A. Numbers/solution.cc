#include <bits/stdc++.h>
using namespace std;

long long gcd( long long a, long long b ) { return b? gcd(b, a%b) : a; }

/*
struct frac {
    long long p, q;
    frac( long long p = 0, long long q = 1 ): p(p), q(q) { norm(); }
    void norm() {
        long long a = gcd( p, q );
        if( a ) { p /= a; q /= a; }
        else q = 1;
        if( q < 0 ) {
            p *= -1;
            q *= -1;
        }
    }
    frac operator +( const frac & o ) {
        long long a = gcd( q, o.q );
        return fract( p*(o.q/a) + o.p*(q/a), q*(o.q/a) );
    }
    frac operator -( const frac & o ) {
        long long a = gcd( q, o.q );
        return fract( p*(o.q/a) - o.p*(q/a), q*(o.q/a) );
    }
    frac operator *( frac o ) {
        long long a = gcd( q, o.p ), b = gcd( o.q, p );
        return fract( (p/b)*(o.p/a), (q/a)*(o.q/b) );
    }
    frac operator /( frac o ) {
        long long a = gcd( q, o.q ), b = gcd( o.p, p );
        return frac( (p/b)*(o.q/a), (q/a)*(o.p/b) );
    }
    bool operator <(const frac & o ) const {
        return p*o.q < o.p*q;
    }
    bool operator ==(const frac & o ) const {
        return p == o.p && o.q == q;
    }
};
*/


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a;
    long long ans = 0;
    cin >> a;
    for( int i = 2; i < a; i++ ) {
        int temp = a;
        while( temp ) {
            ans += temp%i;
            temp /= i;
        }
    }
    long long d = gcd( ans, a-2 );
    ans /= d;
    a = (a-2)/d;
    cout << ans << '/' << a << '\n';
    return 0;
}