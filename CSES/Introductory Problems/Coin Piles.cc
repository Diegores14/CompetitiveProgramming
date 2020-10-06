#include <bits/stdc++.h>
using namespace std;
 
// a = 2*x + y
// 2b = 2x + 4*y
// 2b-a = 3y;
 
// y =  2b-a/3;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t;
    long long a, b;
    cin >> t;
    while( t-- ) {
        cin >> a >> b;
        if( (2*b-a)%3 == 0 && (2*b-a) >= 0 && (2*a-b)%3 == 0 && (2*a-b) >= 0 ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
