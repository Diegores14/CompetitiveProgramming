#include <bits/stdc++.h>
using namespace std;
string s, ans;
int cant[10];

bool solve( int idx, bool top ) {
    if( idx == s.size() ) return true;
    for( int i = 9; i >= 0; i-- ) {
        if( cant[i] && ( top || i <= s[idx]-'0') ) {
            cant[i]--;
            ans[idx] = i+'0';
            if( solve( idx+1, top || i != s[idx]-'0' ) ) return true;
            cant[i]++;
            ans[idx] = s[idx];
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while( cin >> s ) {
        fill( cant, cant+10, 2);
        ans = s;
        solve( 0, false );
        cout << stoll( ans ) << '\n';
    }
    return 0;
}