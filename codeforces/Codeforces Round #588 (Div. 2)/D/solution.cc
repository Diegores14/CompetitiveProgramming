#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    map< long long, long long > m, cant;
    bool used[n];
    memset( used, 0, sizeof used );
    long long a[n], b[n];
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
        cant[a[i]]++;
    }
    for( int i = 0; i < n; i++ ) {
        cin >> b[i];
    }
    long long ans = 0;
    for( long long i: a ) {
        if( cant[i] >= 2 ) {
            for( int j = 0; j < n; j++ ) {
                long long temp = a[j]&i;
                if( !used[j] && (temp == a[j]) ) {
                    ans += b[j];
                    used[j] = true;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}