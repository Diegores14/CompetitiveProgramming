#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n;
    cin >> n >> m;
    cout << max(n*(m/2) + (m%2)*(n/2), m*(n/2) + (n%2)*(m/2)) << '\n';
    return 0;
}