#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n >> b >> a;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    int a1 = a, b1 = b;
    int ans = 0;
    for(int i=0; i<n && (a1 || b1); i++) {
        ans++;
        if(a1 == 0) {
            if(v[i] == 1) {
                a1++;
            }
            b1--;
            continue;
        }
        if(v[i] == 1 && a1 != a && b1 > 0) {
            a1++;
            b1--;
        } else {
            a1--;
        }
        //cout << a1 << ' ' << b1 << '\n';
    }
    cout << ans << '\n';
    return 0;
}