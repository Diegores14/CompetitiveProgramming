#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    vector<long long> v(n), prefix(n+1), ans(n+1);
    for(long long &i: v) {
        cin >> i;
    }
    ans[0] = 1;
    for(int i=n-1; i>=0; i--) {
        prefix[i] = v[i] + prefix[i+1];
    }
    int j=n;
    for(int i=n-1; i>=0; i--) {
        if(prefix[i] > 0) {
            ans[prefix[i]] += ans[prefix[i] - 1];
        }
    }
    if(prefix[0]>0) {
        cout << ans[prefix[0]-1] << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}