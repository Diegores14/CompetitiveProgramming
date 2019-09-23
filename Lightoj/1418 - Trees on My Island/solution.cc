#include <bits/stdc++.h>
using namespace std;
const int tam = 10001;
int n;

struct node {
    long long x, y;
}v[tam];

int gcd( int a, int b ) {
    return b? gcd( b, a%b ) : a;
}

double area( ) {
    long long ans = 0;
    for( int i = 1; i < n; i++ ) {
        ans += v[i].x*v[i-1].y;
        ans -= v[i].y*v[i-1].x;
    }
    ans += v[0].x*v[n-1].y - v[0].y*v[n-1].x;
    return double(abs(ans))/2;
}

long long cantPointsB() {
    long long ans = 0;
    for( int i = 1; i < n; i++ ) {
        ans += gcd( abs(v[i].x - v[i-1].x), abs(v[i].y - v[i-1].y) );
    }
    return ans + gcd( abs(v[0].x - v[n-1].x), abs(v[0].y - v[n-1].y) );
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> n;
        for( int i = 0; i < n; i++ ) {
            cin >> v[i].x >> v[i].y;
        }
        cout << "Case " << cases << ": " << (long long)(area() - cantPointsB()/2 + 1) << '\n';

    }
    return 0;
}