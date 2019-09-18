#include <bits/stdc++.h>
using namespace std;
const int tam = 10005;
int n = 0, m, timer, comp, cant[tam], component[tam], color[tam], tin[tam], low[tam];
list< int > G[tam];
bool used[tam];
stack< int > s;
int ans = 0;

bool bicolored( int idx, int col = 0 ) {
    color[idx] = col;
    for( int to : G[idx] ) {
        if( component[idx] == component[to] ) {
            if( color[to] == -1 ) {
                if( !bicolored(to, col^1) ) return false;
            } else {
                if(color[to] == col) return false;
            }
        }
    }
    return true;
}

void tarjan( int idx, int p = -1 ) {
    //cout << idx << ' ' <<  p << '\n';
    used[ idx ] = true;
    tin[idx] = low[idx] = timer++;
    s.push(idx);
    for( int to : G[idx] ) {
        if( to == p ) continue;
        if( used[to] ) {
            low[idx] = min(low[idx], tin[to] );
        } else {
            tarjan( to, idx );
            low[idx] = min(low[idx], low[to] );
        }
    }
    if( low[idx] == tin[idx] ) {
        comp++;
        while( !s.empty() ) {
            int val = s.top();
            s.pop();
            cant[comp]++;
            component[val] = comp;
            if( val == idx ) break;
        }
        if( !bicolored(idx) ) {
            //cout << idx << '\n';
            ans += cant[comp];
        }
    }
}

int solve() {
    int a, b;
    timer = comp = 0;
    ans = 0;
    memset( cant, 0, sizeof cant );
    memset( component, -1, sizeof component );
    memset( used, 0, sizeof used );
    memset( color, -1, sizeof color );
    while( !s.empty() ) s.pop();
    for( int i = 0; i <= n; i++ ) {
        G[i].clear();
    }
    cin >> n >> m;
    for( int i = 0; i < m; i++ ) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for( int i = 0; i < n; i++ ) {
        if( !used[i] ) {
            tarjan(i);
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": " << solve() << '\n';
    }
    return 0;
}