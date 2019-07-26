#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, temp, l, r; 
    cin >> n;
    long long v[n+1];
    v[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        v[i] = temp + v[i-1];
    }
    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << (v[r] - v[l-1])/10 << '\n';
    }
    return 0;
}