#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin  >>  n;
    if( 1 < n && n < 4 ) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    long long temp = (n+2)/2;
    int ans[n];
    for( int i = 0; i < n; i+=2 ) {
        ans[i] = temp;
        temp++;
    }
    temp = 1;
    for( int i = 1; i < n; i+=2 ) {
        ans[i] = temp;
        temp++;
    }
    for( int i = 0; i < n; i++ ) {
        cout << ans[i] << (i+1 == n? '\n' : ' ');
    }
    return 0;
}
