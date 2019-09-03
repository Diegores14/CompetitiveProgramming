#include <bits/stdc++.h>
using namespace std;
vector< list<int> > G, GT;
vector< int > out;
const int tam = 5e5;
bool used[tam];
int numComp = 0;

void DFS1( int idx ) {
    used[idx] = true;
    for( int &i: G[idx] ) {
        if( !used[i] ) {
            DFS1( i );
        }
    }
    out.emplace_back( idx );
}

void DFS2( int idx ) {
    used[idx] = true;
    for( int &i: GT[idx] ) {
        if( !used[i] ) {
            DFS2( i );
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, a, b, c;
    while( cin >> n >> m ) {
        out.clear();
        numComp = 0;
        G.assign(n, list<int>());
        GT.assign(n, list<int>());
        for( int i = 0; i < m; i++ ) {
            cin >> k >> a >> b; a--; b--;
            G[a].push_back(b);
            GT[b].push_back(a);
            c = b;
            for( int j = 2; j < k; j++ ) {
                cin >> b; b--;
                G[c].push_back(b);
                GT[b].push_back(c);
                c = b;
            }
            if( k != 1) {
                G[c].push_back(a);
                GT[a].push_back(c);
            }
        }
        memset( used, 0, sizeof used );
        for( int i = 0; i < n; i++ ) {
            if(!used[i]) {
                DFS1(i);
            }
        }
        reverse( out.begin(), out.end() );
        memset( used, 0, sizeof used );
        for( int &i : out ) {
            if(!used[i]) {
                numComp++;
                DFS2(i);
            }
        }
        if( numComp == 1 ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}