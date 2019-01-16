#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, a, b;
    cin >> n >> k;
    int p = 0;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        p += b-a+1;
    }
    cout << (k - p%k)%k << '\n';
    return 0;
}