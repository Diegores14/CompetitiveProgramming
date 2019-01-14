#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        ans += (m+i)/5 - i/5;
    }
    cout << ans << '\n';
    return 0;
}