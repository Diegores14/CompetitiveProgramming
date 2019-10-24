#include <bits/stdc++.h>
using namespace std;
int comb[51][51];
typedef vector< vector< unsigned int > > matriz;

void precomputo() {
    comb[0][0] = 1;
    for( int i = 1; i < 51; i++ ) {
        comb[i][0] = 1;
        for( int j = 1; j <= i; j++ ) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
    }
}

matriz identidad( int n ) {
    matriz ans( n, vector< unsigned int >(n, 0) );
    for( int i = 0; i < n; i++ ) {
        ans[i][i] = 1;
    }
    return ans;
}

matriz operator *( matriz &a, matriz &b ) {
    int n = a.size();
    matriz ans( n, vector< unsigned int >(n, 0) );
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            for( int k = 0; k < n; k++ ) {
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

void print( matriz &v ) {
    for( int i = 0; i < v.size(); i++ ) {
        for( int j = 0; j < v[i].size(); j++ ) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

unsigned int exp( long long n, int k ) {
    matriz ans = identidad( k+2 );
    matriz pro(k+2, vector< unsigned int >(k+2, 0) );
    pro[0][0] = 1;
    for( int i = 1; i < k+2; i++ ) pro[0][i] = comb[k][i-1];
    int r = 1;
    for( int i = 1; i < k+2; i++ ) {
        for( int j = 0; j+r < k+2; j++ ) {
            pro[i][j+r] = comb[k-i+1][j];
        }
        r++;
    }
    //print( pro );
    while( n ) {
        if( n&1 ) {
            ans = ans*pro;
        }
        n >>= 1;
        pro = pro*pro;
    }
    unsigned int answer = 0;
    for( int i = 0; i < k+2; i++ ) answer += ans[0][i];
    return answer;
}

void solve() {
    long long n, k;
    cin >> n >> k;
    if( n <= k+1 ) {
        unsigned int ans = 0;
        for( unsigned int i = 1; i <= n; i++ ) {
            unsigned int temp = 1;
            for( int j = 0; j < k; j++ ) 
                temp *= i;
            ans += temp;
        }
        cout << ans << '\n';
    } else {
        cout << exp( n-1 , k ) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomputo();
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}