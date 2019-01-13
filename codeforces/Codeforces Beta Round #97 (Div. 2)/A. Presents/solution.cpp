#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector<int> v(n);
    for(int i=1; i<=n; i++) {
        cin >> temp;
        v[temp-1] = i;
    }
    for(int i=0; i<n; i++) {
        cout << v[i] << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}