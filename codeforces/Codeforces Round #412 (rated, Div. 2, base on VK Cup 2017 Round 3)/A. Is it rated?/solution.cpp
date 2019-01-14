#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    vector<int> v(n), v2(n);
    for(int i=0; i<n; i++) {
        cin >> v[i] >> v2[i];
        if(v[i] != v2[i]) {
            ans = 1;
        }
    }
    if(ans == 0) {
        sort(v.begin(), v.end(), greater<int>());
        if(v == v2) {
            cout << "maybe\n";
        } else {
            cout << "unrated\n";
        }
    } else {
        cout << "rated\n";
    }
    return 0;
}