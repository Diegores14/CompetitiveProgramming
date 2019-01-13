#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i=1; i<=n; i++) {
        v[i] += v[i-1];
    }
    int i=n-1;
    while(v[n] - v[i] <= v[i]) {
        i--;
    }
    cout << n-i << '\n';
    return 0;
}