#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long sum = 0;
    int ans = n-1;
    map<long long, int> se;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        se[sum]++;
        ans = min(ans, n - se[sum]);
    }
    cout << ans << '\n';
    return 0;
}