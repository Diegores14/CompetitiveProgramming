#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    bool ans = false;
    for(int i=n-3; i>=0; i--) {
        ans |= (v[i]+v[i+1] > v[i+2]);
    }
    if(ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}