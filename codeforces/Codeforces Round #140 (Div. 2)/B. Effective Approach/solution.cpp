#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n+1);
    int temp;
    for(int i=1; i<=n; i++) {
        cin >> temp;
        v[temp] = i;
    }
    int m;
    long long a=0, b=0;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> temp;
        a += v[temp];
        b += n-v[temp] + 1;
    }
    cout << a << ' ' << b << '\n';
    return 0;
}