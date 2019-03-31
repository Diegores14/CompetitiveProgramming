#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, mmax = 0, value = 0;
    cin >> n;
    map<int, int> m;
    int v[n];
    int used[n];
    memset(used, 0, sizeof used);
    for(int &i : v) {
        cin >> i;
        m[i]++;
        if(m[i] > mmax) {
            mmax = m[i];
            value = i;
        }
    }
    for(int i=0; i<n; i++) {
        if(v[i] == value) {
            used[i] = 1;
        }
    }
    cout << n - mmax << '\n';
    for(int i = 1; i<n; i++) {
        if(used[i-1] == 1 && used[i] == 0) {
            used[i] = 1;
            cout << ((v[i] > v[i-1])? "2 " : "1 ") << i+1 << ' ' << i << '\n';
            v[i] = value;
        }
    }
    for(int i = n-2; i>=0; i--) {
        if(used[i+1] == 1 && used[i] == 0) {
            used[i] = 1;
            cout << ((v[i] > v[i+1])? "2 " : "1 ") << i+1 << ' ' << i+2 << '\n';
            v[i] = value;
        }
    }
    return 0;
}