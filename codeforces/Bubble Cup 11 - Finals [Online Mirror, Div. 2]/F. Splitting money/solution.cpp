#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long ans = 0, n, x, f;
    cin >> n;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    cin >> x >> f;
    long long temp = x+f;
    for(int &i: v) {
        ans += i/temp;
        i %= temp;
        if(i > x) {
            ans++;
        }
    }
    cout << ans*f << '\n';
    return 0;
}