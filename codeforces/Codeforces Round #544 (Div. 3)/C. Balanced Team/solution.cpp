#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=0; i<n; i++) {
        int l = i, r = n; 
        while(r-l != 1) {
            int mid = (l+r)/2;
            if(v[mid] <= v[i]+5) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans = max(ans, l-i+1);
    }
    cout << ans << '\n';
    return 0;
}