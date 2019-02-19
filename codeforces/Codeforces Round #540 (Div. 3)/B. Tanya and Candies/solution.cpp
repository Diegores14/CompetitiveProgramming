#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    vector< vector<long long> > prefix(2, vector<long long> (n+1, 0));
    for(int i=1; i<=n; i++) {
        cin >> v[i-1];
        prefix[0][i] = prefix[0][i-1];
        prefix[1][i] = prefix[1][i-1];
        prefix[i&1][i] += v[i-1];
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        long long temp[2];
        temp[0] = prefix[0][i-1]; temp[1] = prefix[1][i-1]; 
        temp[1] += prefix[0][n] - prefix[0][i];
        temp[0] += prefix[1][n] - prefix[1][i];
        ans += (temp[0] == temp[1]);
    }
    cout << ans << '\n';
    return 0;
}