#include <bits/stdc++.h>
using namespace std;

long double check(long long n) {
    if(n <= 0) {
        return 1;
    }
    return (long double) n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, h, temp = 0, aux;
    long long sum = 0;
    cin >> n >> m >> h;
    for(int i=1; i<=m; i++) {
        cin >> aux;
        if(i == h && aux) {
            temp = aux;
        }
        sum += aux;
    }
    long double ans = 1;
    if(sum < n) {
        cout << -1 << '\n';
    } else {
        if(sum - temp < n - 1) {
            cout << 1 << '\n';
        } else {
            temp--;
            sum--;
            n--;
            for(int i=1; i<=n; i++) {
                ans *= check(sum - temp - n + i) / check(sum - n + i);
            }
            cout << fixed << setprecision(15) << 1 - ans << '\n';
        }
    }
    return 0;
}