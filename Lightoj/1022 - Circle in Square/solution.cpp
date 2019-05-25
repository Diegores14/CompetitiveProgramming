#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    long double r;
    cin >> t;
    cout << fixed << setprecision(2);
    for(int cases = 1; cases <= t; cases++) {
        cin >> r;
        cout << "Case " << cases << ": " << (4 - pi)*r*r << '\n';
    }
    return 0;
}