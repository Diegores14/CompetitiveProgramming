#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b, t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        long double sum = a*b;
        if(4*b <= a) {
            sum += (a*b - 2*b*b);
        } else {
            sum += (long double) (a*a)/8;
        }
        if(b == 0) {
            cout << 1 << '\n';
            continue;
        }
        if(a == 0) {
            cout << 0.5 << '\n';
            continue;
        }
        cout << fixed << setprecision(15) << sum / (2*a*b) << '\n';
    }
    return 0;
}