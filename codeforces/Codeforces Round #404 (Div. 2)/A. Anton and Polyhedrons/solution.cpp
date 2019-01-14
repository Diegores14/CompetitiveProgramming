#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long ans = 0;
    map<string, int> m;
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;
    string s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        ans += m[s];
    }
    cout << ans << '\n';
    return 0;
}