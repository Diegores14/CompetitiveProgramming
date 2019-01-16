#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> L, R, val(n);
    char c;
    for(int i=0; i<n; i++) {
        cin >> c;
        if(c == 'L') {
            L.emplace_back(i);
        } else {
            R.emplace_back(i);
        }
    }
    for(int &i: val) {
        cin >> i;
    }
    int i=0, j=0;
    long long ans = 1e15;
    while(i < R.size() && j < L.size()) {
        while(j < L.size() && L[j] < R[i]) {
            j++;
        }
        if(j < L.size()) {
            ans = min(ans, ((1LL * val[L[j]]-val[R[i]])>>1));
        }
        i++;
    }
    if(ans == 1e15) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}