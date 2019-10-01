#include <bits/stdc++.h>
using namespace std;
const int tam = 40005;
list< int > G[tam], GT[tam];
bool used[tam];
int len, component[tam];
vector<int> order;
vector<bool> ans;
int n, m;


void DFS1( int idx ) {
    used[idx] = true;
    for( int i : G[idx] ) {
        if( !used[i] ) {
            DFS1( i );
        }
    }
    order.push_back( idx );
}

void DFS2( int idx ) {
    component[idx] = len;
    for( int i : GT[idx] ) {
        if( component[i] == -1 ) {
            DFS2( i );
        }
    }
}

int sat() {
    for( int i = 0; i < (m<<1); i++ ) {
        if( !used[i] ) {
            DFS1( i );
        }
    }
    reverse( order.begin(), order.end() );
    for( int i : order ) {
        if( component[i] == -1 ) {
            DFS2( i );
            len++;
        }
    }
    int sz = 0;
    ans.assign( m, false );
    for( int i = 0; i < (m<<1); i += 2 ) {
        if( component[i] == component[i+1] ) {
            return -1;
        }
        ans[i/2] = component[i] > component[i+1];
        sz += component[i] > component[i+1];
    }
    return sz;
}

void add( char c1, int a, char c2, int b) {
    a *= 2;
    b *= 2;
    if( c1 == '-' ) {
        a += 1;
    }
    if( c2 == '-' ) {
        b += 1;
    }
    //cout << a << ' ' << b << '\n';
    // not(a) -> b
    G[a^1].push_back(b);
    GT[b].push_back(a^1);
    // not(b) -> a
    G[b^1].push_back(a);
    GT[a].push_back(b^1);
}

void solve() {
    int x = sat();
    if( x != -1 ) {
        cout << "Yes\n";
        cout << x;
        for( int i = 0; i < m; i++ ) {
            if( ans[i] ) {
                cout << ' ' << i+1;
            }
        }
        cout << '\n';
    } else {
        cout << "No\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b;
    char c1, c2;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        len = 0;
        memset( component, -1, sizeof component );
        memset( used, 0, sizeof used );
        order.clear();
        for( int i = 0; i < tam; i++ ) {
            G[i].clear();
            GT[i].clear();
        }
        cin >> n >> m;
        for( int i = 0; i < n; i++ ) {
            cin >> c1 >> a >> c2 >> b;
            a--; b--;
            add( c1, a, c2, b );
        }
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
} 