#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int v[n];
    int mx = -1, index;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] >= 0) v[i] = -v[i] - 1;
        if(abs(v[i]) > mx) {
            mx = abs(v[i]);
            index = i;
        }
    }
    if(n&1) {
        v[index] = -v[index] - 1;
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << ((i == n-1)? '\n' : ' ');
    }
    return 0;
}