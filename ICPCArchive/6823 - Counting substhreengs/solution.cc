#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6+5;
long long v[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s) {
        v[0] = 1;
        v[1] = v[2] = 0;
        int n = s.size();
        long long ans = 0;
        int sum = 0;
        for( int i = n-1; i >= 0; i-- ) {
            if( '0' <= s[i] && s[i] <= '9' ) {
                sum = (s[i]-'0' + sum)%3;
                ans += v[sum];
                v[sum]++;
            } else {
                sum = 0;
                v[0] = 1;
                v[1] = v[2] = 0;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}