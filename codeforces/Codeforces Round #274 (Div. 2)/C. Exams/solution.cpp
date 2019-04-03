#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    pair< int, int > v[n];
    for(auto &i: v) {
        cin >> i.first >> i.second;
    }
    sort(v, v+n);
    int ans = 0;
    for(auto &i: v) {
        if(ans <= i.second) {
            ans = i.second;
        } else {
            ans = i.first;
        }
    }
    cout << ans << '\n';
    return 0;
}