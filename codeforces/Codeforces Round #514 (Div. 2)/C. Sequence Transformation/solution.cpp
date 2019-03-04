#include <bits/stdc++.h>
using namespace std;
int sec[(int)1e6+7];
int ans[(int)1e6+7];
int l = 0;

void solve(int n, int mul) {
    if(n == 1) {
        ans[l++] = mul * sec[n-1];
        return;
    }
    if(n == 2) {
        ans[l++] = mul; ans[l++] = mul * sec[n-1];
        return;
    }
    if(n == 3) {
        ans[l++] = mul; ans[l++] = mul; ans[l++] = mul * sec[n-1];
        return;
    }
    for(int i=0; i < n; i++) { if(sec[i]&1) ans[l++] = mul; }
    for(int i=0; i < n/2; i++) { sec[i] = sec[i*2+1]/2; }
    solve(n/2, mul*2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        sec[i-1] = i;
    }
    solve(n, 1);
    for(int i=0; i<n; i++) {
        cout << ans[i] << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}