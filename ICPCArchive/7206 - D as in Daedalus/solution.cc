#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp, b, d;
    while( cin >> n >> m ) {
        long long ansBefore = 0, ansAfter = 0;
        for( int i = 0; i < m; i++ ) {
            cin >> b >> d;
            long long sum = d;
            for( int j = 1; j < n; j++ ) {
                cin >> temp;
                sum += temp;
            }
            int last = 0;
            if( sum <= b ) ansBefore += d;
            for( int j = 1; j <= 10000; j *= 10) {
                if( sum - d + j <= b ) {
                    last = j;
                }
            }
            if( sum - d + last <= b ) ansAfter += last;
        }
        cout << ansAfter - ansBefore << '\n';
    }
    return 0;
}