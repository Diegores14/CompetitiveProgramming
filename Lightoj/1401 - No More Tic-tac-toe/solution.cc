#include <bits/stdc++.h>
using namespace std;
const int tam = 105;
int grundy[tam][3][3];
/*
                // the first
                a = ((j==0)? 1: 3-j); b = ((j==0)? 2: 3-j);
                int c1 = grundy[0][j][a]^grundy[i-1][a][k];
                int c2 = grundy[0][j][b]^grundy[i-1][b][k];
                used[c1] = true; used[c2] = true;
                // the second
                a = ((k==0)? 1: 3-k); b = ((k==0)? 2: 3-k);
                c1 = grundy[i-1][j][a]^grundy[0][a][k];
                c2 = grundy[i-1][j][b]^grundy[0][b][k];
                used[c1] = true; used[c2] = true; */

void precompute() {
    for( int i = 0; i < 3; i++ ) {
        for( int j = 0; j < 3; j++ ) {
            grundy[0][i][j] = 0;
            grundy[1][i][j] = 1;
        }
    }
    grundy[1][1][2] = 0;
    grundy[1][2][1] = 0;
    for( int i = 2; i < tam; i++ ) {
        for( int j = 0; j < 3; j++ ) {
            for( int k = 0; k < 3; k++ ) {
                bool used[tam+tam];
                memset( used, 0, sizeof used );
                for( int r = 2; r < i; r++ ) {
                    int a = r-1, b = i-r;
                    int c1 = grundy[a][j][1]^grundy[b][1][k];
                    int c2 = grundy[a][j][2]^grundy[b][2][k];
                    used[c1] = true;
                    used[c2] = true;
                }
                int a, b;
                if( j != 2 ) {
                    a = grundy[0][j][2];
                    b = grundy[i-1][2][k];
                    used[a^b] = true;
                }
                if( j != 1 ) {
                    a = grundy[0][j][1];
                    b = grundy[i-1][1][k];
                    used[a^b] = true;
                }
                if( k != 2 ) {
                    a = grundy[i-1][j][2];
                    b = grundy[0][2][k];
                    used[a^b] = true;
                }
                if( k != 1 ) {
                    a = grundy[i-1][j][1];
                    b = grundy[0][1][k];
                    used[a^b] = true;
                }
                int val = 0;
                while( used[val] ) val++;
                grundy[i][j][k] = val;
            }
        }
    }
}

void solve() {
    map<char, int > m;
    m['X'] = 1;
    m['O'] = 2;
    string s;
    cin >> s;
    int ans = 0;
    int len = 0;
    int c = 0;
    int sz = 0;
    for( int i = 0; i < s.size(); i++ ) {
        if( s[i] == '.' ) {
            len++;
        } else {
            sz++;
            ans ^= grundy[len][c][ m[s[i]] ];
            c = m[s[i]];
            len = 0;
        }
    }
    ans ^= grundy[len][c][0];
    if( sz&1 ) {
        cout << (ans? "No" : "Yes" ) << '\n';
    } else {
        cout << (ans? "Yes" : "No" ) << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}