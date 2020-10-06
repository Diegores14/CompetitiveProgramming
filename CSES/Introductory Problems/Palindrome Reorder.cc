#include <bits/stdc++.h>
using namespace std;
int cant[255];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    for( int i = 0; i < n; i++ ) {
        cant[s[i]]++;
    }
    int odd = 0;
    int pos = 0;
    for( int i = 'A'; i <= 'Z'; i++ ) {
        odd += cant[i]&1;
        if( cant[i]&1 ) {
            pos = i;
        }
    }
    string ans(n, 'A');
    if( odd > 1 ) {
        cout << "NO SOLUTION\n";
    } else {
        int len = 0;
        for( int i='A'; i <= 'Z'; i++ ) {
            while( cant[i] > 1 ) {
                cant[i] -= 2;
                ans[len] = ans[n-len-1] = char(i);
                len++;
            }
        }
        if( odd ) {
            ans[len] = char(pos);
        }
        cout << ans << '\n';
    }
    return 0;
}
