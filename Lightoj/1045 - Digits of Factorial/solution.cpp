#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6+5;
long double v[tam];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, b;
    v[0] = 0;
    for(int i = 1; i < tam; i++) {
        v[i] = log10(i) + v[i-1];
    }
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cin >> n >> b;
        cout << "Case " << r << ": " << int(v[n]/log10(b)) + 1 << '\n';
    }
    return 0;
}