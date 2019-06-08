#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, s;
    while(cin >> n >> s) {
        long long sum = 0, temp;
        int l = -1, r = -1;
        map< int, int > m;
        m[0] = 0;
        bool ans = false;
        for( int i = 0; i < n; i++ ) {
            cin >> temp;
            sum += temp;
            if(!ans && m.count(sum - s) ) {
                ans = true;
                l = m[sum-s] + 1;
                r = i + 1;
            }
            m[sum] = i+1;
        }
        if( ans ) {
            cout << l << ' ' << r << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}