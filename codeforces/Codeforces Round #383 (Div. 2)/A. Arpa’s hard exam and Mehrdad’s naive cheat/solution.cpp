#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v({6,8,4,2});
    int n;
    cin >> n;
    if(n)
        cout  << v[n%4] << '\n';
    else
        cout << 1 << '\n';
    return 0;
}