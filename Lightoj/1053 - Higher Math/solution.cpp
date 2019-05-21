#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    long long v[3];
    cin >> t;
    for( int r = 1; r <= t; r++ ) {
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v+3);
        cout << "Case " << r << ": " << ((v[0]*v[0] + v[1]*v[1] == v[2]*v[2])? "yes" : "no") << '\n';
    }
    return 0;
}