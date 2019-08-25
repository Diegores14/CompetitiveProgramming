#include <bits/stdc++.h>
using namespace std;
const int tam = 101;
pair< int, int > v[tam];
int temp[ 4 ][4];
int t, n, k;

long long area( int idx, int paridad, int x1, int x2, int y1, int y2) {
    if( idx == k) return 0;
    long long ans = 0;
    int x1_ = max(x1, temp[idx][0] );
    int x2_ = min(x2, temp[idx][1] );
    int y1_ = max(y1, temp[idx][2] );
    int y2_ = min(y2, temp[idx][3] );
    if(x1_ < x2_ && y1 < y2_) {
        ans = (paridad? 1LL : -1LL)*( x2_ - x1_ )*( y2_ - y1_ );
        ans += area( idx+1, paridad^1, x1_, x2_, y1_, y2_ );
    }
    ans += area( idx+1, paridad, x1, x2, y1, y2 );
    return ans;
}

bool solve(int idx) {
    if( idx == k ) {
        return area(0, 1, 0, n-1, 0, n-1) == 1LL*(n-1)*(n-1);
    }
    for( int i = 0; i < 4; i++) {
        if( i == 0 || i == 3) {
            temp[idx][0] = 0;
            temp[idx][1] = v[idx].first;
        }
        if( i == 1 || i == 2) {
            temp[idx][0] = v[idx].first;
            temp[idx][1] = n-1;
        }
        if( i == 0 || i == 1) {
            temp[idx][2] = v[idx].second;
            temp[idx][3] = n-1;
        }
        if( i == 2 || i == 3) {
            temp[idx][2] = 0;
            temp[idx][3] = v[idx].second;
        }
        if( solve( idx+1 ) ) 
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while( t-- ) {
        cin >> k >> n;
        for( int i = 0; i < k; i++ ) {
            cin >> v[i].first >> v[i].second;
        }
        if( k >= 4 ) cout << "yes\n";
        else {
            cout << ( solve(0)? "yes" : "no" ) << '\n';
        }
    }
    return 0;
}