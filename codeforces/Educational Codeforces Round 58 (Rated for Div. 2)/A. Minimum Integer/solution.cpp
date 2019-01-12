#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, l, r, d;
    cin >> t;
    while(t--) {
        cin >> l  >> r >> d;
        if(d < l) {
            cout << d << '\n';
        } else {
            cout << 1LL * (r/d + 1) * d << '\n'; 
        }
    }
    return 0;
}