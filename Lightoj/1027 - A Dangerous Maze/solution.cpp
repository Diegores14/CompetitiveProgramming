#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, temp;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            a += abs(temp);
            b += temp > 0;
        }
        int d = gcd(a, b);
        cout << "Case " << cases << ": ";
        if(b)
        cout << a/d << '/' << b/d << '\n';
        else 
        cout << "inf\n";
    }
    return 0;
}