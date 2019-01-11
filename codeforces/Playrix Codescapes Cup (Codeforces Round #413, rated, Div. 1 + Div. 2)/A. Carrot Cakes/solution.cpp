#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    long long limit = ((n + k -1)/k - 1) * t;
    if(d < limit) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}