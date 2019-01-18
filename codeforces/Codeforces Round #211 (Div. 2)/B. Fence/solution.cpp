#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = 1e9;
    int j;
    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    for(int i=0; i+k<=n; i++) {
        if(ans > v[i+k]-v[i]) {
            j = i+1;
            ans = v[i+k]-v[i];
        }
    }
    cout << j << '\n';
    return 0;
}