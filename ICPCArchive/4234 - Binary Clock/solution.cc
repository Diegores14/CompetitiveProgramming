#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, H, M, S;
    char x;
    cin >> t;
    for( int i = 1; i <= t; i++ ) {
        cin >> H >> x >> M >> x >> S;
        cout << i << ' ';
        for( int i = 5; i >= 0; i-- ) {
            cout << ((H>>i)&1) << ((M>>i)&1) << ((S>>i)&1);
        }
        cout << ' ';
        for( int i = 5; i >= 0; i-- ) {
            cout << ((H>>i)&1);
        }
        for( int i = 5; i >= 0; i-- ) {
            cout << ((M>>i)&1);
        }
        for( int i = 5; i >= 0; i-- ) {
            cout << ((S>>i)&1);
        }
        cout << '\n';
    }
    return 0;
}