#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int v[n];
    for( int &i: v ) {
        cin >> i;
    }
    long double ans = 0;
    for(int i = 0; i < n; i++ ) {
        ans += (long double)1/v[i];
    }
    cout << fixed << setprecision(10) << 1/ans << '\n';
    return 0;
}