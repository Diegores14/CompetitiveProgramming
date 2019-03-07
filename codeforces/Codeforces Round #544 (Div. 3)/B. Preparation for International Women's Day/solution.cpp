#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, temp;
    cin >> n >> k;
    vector<int> v(k, 0);
    for(int i=0; i<n; i++) {
        cin >> temp;
        v[temp%k]++;
    }
    int ans = 0;
    ans += v[0]/2;
    v[0] = 0;
    for(int i=1; i<k; i++) {
        if(i != k-i){
            temp = min(v[i], v[k-i]);
            ans += temp;
            v[i] -= temp;
            v[k-i] -= temp;
        } else {
            ans += v[i]/2;
        }
    }
    cout << ans*2 << '\n';
    return 0;
}