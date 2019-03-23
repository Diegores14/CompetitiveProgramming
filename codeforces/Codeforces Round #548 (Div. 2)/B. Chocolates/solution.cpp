#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int v[n];
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    long long ans = 0;
    long long temp = v[n-1];
    for(int i = n-1; i >= 0; i--) {
        if(temp <= v[i]) {
            ans += temp;
            temp--;
        } else {
            ans += v[i];
            temp = v[i] - 1;
        }
        temp = max(0LL, temp);
    }
    cout << ans << '\n';
    return 0;
}