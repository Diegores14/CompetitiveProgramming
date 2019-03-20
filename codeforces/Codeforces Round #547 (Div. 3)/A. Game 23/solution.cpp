#include <bits/stdc++.h>
using namespace std;

int solve(int & n, int k) {
    int ans = 0;
    while(n%k == 0) {
        ans++;
        n /= k;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int temp1 = 0, temp2 = 0;
    int ans1 = 0,  ans2 = 0;
    temp1 += solve(n, 2);
    temp2 += solve(n, 3);
    ans1 += solve(m, 2);
    ans2 += solve(m, 3);
    if(n == m && temp1 <= ans1 && temp2 <= ans2) {
        cout << ans1 + ans2 - temp1 - temp2  << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}