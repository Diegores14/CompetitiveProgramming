#include <bits/stdc++.h>
using namespace std;
const int tam = 10005;
int grundyNumbers[tam];
int used[tam];

void precalculation() {
    memset( grundyNumbers, 0, sizeof grundyNumbers );
    for( int i = 3; i < tam; i++ ) {
        memset(used, 0, sizeof used);
        for( int a = 1, b = i-1; a < b; a++, b-- ) {
            used[ grundyNumbers[a]^grundyNumbers[b] ] = true;
        }
        int k = 0;
        while( used[k] ) k++;
        grundyNumbers[i] = k;
    }
}

void solve() {
    int n, temp; 
    int ans = 0; 
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        ans ^= grundyNumbers[temp];
    }
    cout << ( ans? "Alice": "Bob" ) << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    precalculation();
    int t; 
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}