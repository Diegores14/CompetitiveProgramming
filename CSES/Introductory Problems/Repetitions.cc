#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    long long ans = 1;
    long long sum = 1;
    long long n = s.size();
    for( int i = 1; i < n; i++ ) {
        if( s[i] == s[i-1] ) {
            sum++;
        } else {
            sum = 1;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
