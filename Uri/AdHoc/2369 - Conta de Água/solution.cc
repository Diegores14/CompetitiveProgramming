#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long ans = 7;
    if( n > 10 ) {
        ans += min(20, n-10);
    }
    if( n > 30 ) {
        ans += 2*min(70, n-30);
    }
    if( n > 100 ) {
        ans += 5*(n-100);
    }
    cout << ans << '\n';
    return 0;
}