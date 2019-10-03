#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, temp;
    cin >> t;
    while( t-- ) {
        cin >> n;
        long long sum = 0;
        for( int i = 0; i < n; i++ ) {
            cin >> temp;
            sum += temp;
        }
        cout << (sum+n-1)/n << '\n';
    }
    return 0;
}