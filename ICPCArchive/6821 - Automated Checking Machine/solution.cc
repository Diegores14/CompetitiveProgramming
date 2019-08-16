#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v1[5], v2[5];
    while( cin >> v1[0] ) {
        for(int i = 1; i < 5; i++) {
            cin >> v1[i];
        }
        for(int i = 0; i < 5; i++) {
            cin >> v2[i];
        }
        int ans = 1;
        for( int i = 0; i < 5; i++ ) {
            ans &= (v1[i]^v2[i]);
        }
        cout << (ans? "Y" : "N") << '\n';
    }
    return 0;
}