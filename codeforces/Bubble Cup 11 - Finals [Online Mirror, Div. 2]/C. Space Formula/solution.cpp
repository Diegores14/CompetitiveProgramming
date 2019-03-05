#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    vector<int> s(n), p(n);
    for(int &i: s) {
        cin >> i;
    }
    for(int &i: p) {
        cin >> i;
    }
    int r = n-1;
    int ans = n;
    int temp = s[d-1] + p[0];
    for(int i=0; i<n; i++) {
        if(i != d-1 && s[i] + p[r] <= temp) {
            r--;
            ans--;
        }
    }
    cout << ans << '\n';
    return 0;
}