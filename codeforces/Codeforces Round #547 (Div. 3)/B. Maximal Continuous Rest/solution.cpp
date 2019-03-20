#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector<int> v(2*n, 0);
    for(int i=0; i<n; i++) {
        cin >> temp;
        v[i] = temp;
        v[i+n] = temp;
    }
    temp = 0;
    int ans = 0;
    for(int i=0; i < 2*n; i++) {
        if(v[i] == 0) {
            temp = 0;
            continue;
        }
        temp += v[i];
        ans = max(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}