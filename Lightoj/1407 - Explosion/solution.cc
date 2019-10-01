#include <bits/stdc++.h>
using namespace std;
const int tam = 2005;
list<int> G[tam], GT[tam];
bool used[tam];
int component[tam];
vector< int > order, ans;
int in[6][4];
int len = 0, n, m, k;

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

bool sat() {
    len = 0;
    order.clear();
    memset( used, 0, sizeof used );
    memset( component, -1, sizeof component );
    for( int i = 0; i < (n<<1); i++ ) {
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
    ans.clear();
    for( int i = 0; i < (n<<1); i += 2 ) {
        if( component[i] == component[i+1] ) {
            return 0;
        }
        if( component[i] > component[i+1]) ans.push_back((i/2)+1);
    }
    return 1;
}

void add1( bool c1, int a, bool c2, int b ) {
    a *= 2;
    b *= 2;
    if( c1 ) a += 1;
    if( c2 ) b += 1;
    G[a^1].push_back(b);
    GT[b].push_back(a^1);
    G[b^1].push_back(a);
    GT[a].push_back(b^1);
}

bool solve1( int idx = 0 ) {
    if( idx == k ) return sat();
    if( in[idx][0] == 1 ) {
        for( int i = 1; i < 4; i++ ) {
            // !x -> x
            int a = (in[idx][i]-1)*2;
            G[a^1].push_back(a);
            GT[a].push_back(a^1);
            if( sat() ) {
                if( solve1(idx+1) ) return 1;
            }
            G[a^1].pop_back();
            GT[a].pop_back();
        }
    } else {
        for( int i = 1; i < 4; i++ ) {
            // x -> !x
            int a = (in[idx][i]-1)*2;
            G[a].push_back(a^1);
            GT[a^1].push_back(a);
            if( sat() ) {
                if( solve1(idx+1) ) return 1;
            }
            G[a].pop_back();
            GT[a^1].pop_back();
        }
    }
    return 0;
}

void solve() {
    int typ, a, b, c;
    cin >> n >> m >> k;
    for( int i = 0; i < m; i++ ) {
        cin >> typ >> a >> b; a--; b--;
        if( typ == 1 ) { // ( a || b )
            add1( 0, a, 0, b );
            continue;
        }
        if( typ == 2 ) { // ( a || !b )
            add1( 0, a, 1, b );
            continue;
        }
        if( typ == 3 ) { // ( !a || !b )
            add1( 1, a, 1, b );
            continue;
        }
        if( typ == 4 ) { // ( a || b ) && ( !a || !b ) 
            add1( 1, a, 1, b );
            add1( 0, a, 0, b );
        }
    }
    for( int i = 0; i < k; i++ ) 
        for( int j = 0; j < 4; j++ ) cin >> in[i][j];
    if( solve1( 0 ) ) {
        cout << "Possible " << ans.size();
        for( int i : ans ) {
            cout << ' ' << i;
        }
        cout << ".\n";
    } else {
        cout << "Impossible.\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        for( int i = 0; i < tam; i++ ) {
            G[i].clear();
            GT[i].clear();
        }
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}