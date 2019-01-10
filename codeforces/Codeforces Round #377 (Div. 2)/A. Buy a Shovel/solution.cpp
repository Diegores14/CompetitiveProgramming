#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long k, r;
    int ans = 1;
    cin >> k >> r;
    long long temp = k;
    while((temp-r)%10 && temp%10) {
        temp += k;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}