#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    string s;
    cin >> n >> k >> s;
    if( n == 1 && k) {
        s[0] = '0';
        k--;
    } else {
        if( s[0] != '1' && k ) {
            s[0] = '1';
            k--;
        }
        for( int i = 1; i <n && k; i++ ) {
            if( s[i] != '0' && k ) {
                s[i] = '0';
                k--;
            }
        }
    }
    cout << s << '\n';
    return 0;
}