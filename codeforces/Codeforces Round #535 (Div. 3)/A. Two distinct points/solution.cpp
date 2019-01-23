#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, l1, r1, l2, r2;
    cin >> q;
    while(q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if(r2!=l1) {
            cout << l1 << ' ' << r2 << '\n';
        } else {
            if(r1 != l2) {
                cout << r1 << ' ' << l2 << '\n';
            }
        }
    }
    return 0;
}