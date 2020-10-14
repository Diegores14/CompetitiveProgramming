#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+7;
int prefix[tam];
long long v[tam];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, tp, l, r;
    cin >> n >> q;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
        prefix[i+1] = prefix[i]^v[i];
    }
    while( q-- ) {
        cin >> l >> r;
        cout << (prefix[r]^prefix[l-1]) << '\n';
    }
    return 0;
}