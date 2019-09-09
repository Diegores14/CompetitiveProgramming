#include <bits/stdc++.h>
using namespace std;
const int tam = 1005;
int v[tam];
int n, k;

bool check( int x ) {
    int accum = 0;
    int cant = k;
    for( int i = 0; i <= n; i++ ) {
        if( accum + v[i] <= x ) {
            accum += v[i];
        } else {
            if( v[i] > x ) return false;
            else {
                accum = v[i];
                cant--;
            }
        }
    }
    return cant >= 0;
}

void solve() {
    cin >> n >> k;
    for( int i = 0; i <= n; i++ ) {
        cin >> v[i];
    }
    int l = -1, r = 30000000;
    while( r-l != 1 ) {
        int mid = (l+r)/2;
        if( check( mid ) ) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    vector< int > ans;
    ans.push_back(-1);
    int accum = 0;
    for(int i = 0; i <= n; i++ ) {
        if( accum + v[i] <= r ) {
            accum += v[i];
        } else {
            accum = v[i];
            ans.push_back(i);
            k--;
        }
    }
    ans.push_back(n+1);
    int limit = n+1;
    int i = ans.size()-1;
    while(k > 0) {
        if( limit != ans[i-1]+1 ) {
            ans.push_back( --limit );
            k--;
        } else {
            limit = ans[i-1];
            i--;
        }
    }
    sort( ans.begin(), ans.end() );
    int j = 1;
    accum = 0;
    for( i = 0; i <= n; i++ ) {
        accum += v[i];
        if( i+1 == ans[j] ) {
            cout << accum << '\n';
            accum = 0;
            j++;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}