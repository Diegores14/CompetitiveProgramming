#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    return b? GCD(b, a%b) : a;
}

int LCM( int a , int b ) {
    return (a*b)/GCD(a, b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> a >> b;
        cout << cases << ' ' << LCM(a, b) << ' ' << GCD(a, b) << '\n'; 
    }
    return 0;
}