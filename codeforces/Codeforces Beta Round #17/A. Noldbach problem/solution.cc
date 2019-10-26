#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    int a = 3, b = 2;
    cin >> n >> k;
    int sum = 0;
    bool v[10*n];
    memset( v, 0, sizeof v );
    for( int i = 4; i <= n; i++ ) {
        bool ok = true;
        for( int j = 2; j*j <= i; j++ ) {
            if( i%j == 0 ) {
                ok = false;
                break;
            }
        }
        if( ok ) {
            v[a+b+1] = true;
            if( v[i] ) sum++;
            b = a;
            a = i;
        }
    }
    cout << ((k <= sum)? "YES": "NO") << '\n';
    return 0;
}