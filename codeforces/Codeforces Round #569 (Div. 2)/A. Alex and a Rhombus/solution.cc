#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    long long  ans = 1, acc = 4;
    cin >> n;
    while(--n) {
        ans += acc;
        acc += 4;
    }
    cout << ans << '\n';
    return 0;
}