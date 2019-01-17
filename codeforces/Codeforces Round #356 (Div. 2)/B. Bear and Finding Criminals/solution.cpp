#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a;
    cin >> n >> a;
    a--;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    int limit = max(a+1,n-a);
    int ans = v[a]==1;
    for(int i=1; i<limit; i++) {
        int l = a-i, r = a+i;
        if(0 <= l && r < n && v[l] == 1 && v[r] == 1){
            ans+=2;
        }
        if(l < 0 && v[r] == 1) {
            ans++;
        }
        if(r >= n && v[l] == 1) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}