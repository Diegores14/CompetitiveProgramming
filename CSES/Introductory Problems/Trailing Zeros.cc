#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin  >>  n;
    long long ans = 0;
    long long b = 5;
    while( b <= n ) {
        ans += n/b;
        b *= 5;
    }
    cout << ans << '\n';
    return 0;
}
