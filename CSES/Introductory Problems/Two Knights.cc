#include <bits/stdc++.h>
using namespace std;
 
long long answer( long long n ) {
    long long l = n*n;
    long long ans = l*(l-1)/2;
    ans -= 2*max(0LL, n-2)*(n-1);
    ans -= 2*(n-1)*max(0LL, n-2);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin  >>  n;
    for( int i = 1; i <= n; i++ ) {
        cout << answer(i) << '\n';
    }
    return 0;
}
