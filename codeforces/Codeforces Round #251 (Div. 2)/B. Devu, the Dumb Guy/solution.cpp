#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    for(int &i: v) {
        ans += 1LL * i * x;
        x--;
        if(x==0) {
            x=1;
        }
    }
    cout << ans << '\n';
    return 0;
}