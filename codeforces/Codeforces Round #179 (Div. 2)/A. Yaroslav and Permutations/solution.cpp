#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<int, int> m;
    int n, temp;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        m[temp]++;
    }
    int limit = (n + 1)>>1;
    for(auto i: m) {
        if(i.second > limit) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}