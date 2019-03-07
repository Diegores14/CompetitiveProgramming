#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    return b? GCD(b, a%b) : a;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
    }
    long long ans = 0, aux = 0;
    map<long double, long long> m;
    for(int i=0; i<n; i++) {
        if(a[i] == 0 && b[i] == 0) {
            aux++;
            continue;
        }
        if(b[i] == 0) {
            m[0]++;
            ans = max(m[0], ans);
            continue;
        }
        if(a[i]) {
            long double d = (long double)-1*b[i]/a[i];
            m[d]++;
            ans = max(ans, m[d]);
        }
    }
    cout << ans + aux << '\n';
}