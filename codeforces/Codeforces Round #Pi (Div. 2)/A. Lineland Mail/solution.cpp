#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    for(int i=0; i<n; i++) {
        int temp = 2e9;
        if(0<i)
            temp = min(temp, abs(v[i]-v[i-1]));
        if(i<n-1)
            temp = min(temp, abs(v[i]-v[i+1]));
        cout << temp << ' ' << max(abs(v[i]-v[0]), abs(v[i]-v[n-1])) << '\n';
    }
    return 0;
}