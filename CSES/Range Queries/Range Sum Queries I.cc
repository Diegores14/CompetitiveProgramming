#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    long long prefix[n+1];
    prefix[0] = 0;
    for( int i = 0; i < n; i++ ) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
    }
    while( q-- ) {
        long long a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
    }
    return 0;
}
