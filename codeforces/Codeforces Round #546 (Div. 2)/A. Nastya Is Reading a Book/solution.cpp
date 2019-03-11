#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector< pair<int, int> > v(n);
    for(auto &i: v ) {
        cin >> i.first >> i.second;
    }
    int q;
    cin >> q;
    int i=0; 
    for(; i<n; i++) {
        if(v[i].first <= q && q <= v[i].second) {
            break;
        }
    }
    cout << n - i << '\n';
    return 0;
}