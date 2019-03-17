#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, temp, mmax = 0, m = 10000000;
    cin >> n >> k;
    vector<int> v(10000005, 0);
    for(int i=0; i<n; i++) {
        cin >> temp;
        v[temp]++;
        mmax = max(mmax, temp);
        m = min(m, temp);
    }
    for(int i=1; i<10000001; i++) {
        v[i] += v[i-1];
    }
    if(m <= k+1) {
        cout << m << '\n';
    } else {
        int ans = k+1;
        for(int i = ans; i <= m; i++) {
            temp = 0;
            for(int j=1; j*i <= mmax; j++) {
                temp += v[j*i+k] - v[j*i - 1];
            }
            if(temp == n) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}