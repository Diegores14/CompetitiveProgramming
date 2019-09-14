#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    while( cin >> t ) {
        int temp, ans = 0; 
        for( int i = 0; i < 5; i++ ) {
            cin >> temp;
            ans += temp == t;
        }
        cout << ans << '\n';
    }
    return 0;
}