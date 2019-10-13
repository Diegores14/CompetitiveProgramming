#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, k;
    double p;
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n  >> m >> k >> p;
        cout << "Case " << cases << ": " << n*p*k << '\n';
    }
    return 0;
}