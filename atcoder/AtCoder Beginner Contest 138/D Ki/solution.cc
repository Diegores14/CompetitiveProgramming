#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6;
vector< list< int > > G(tam);
long long v[tam];
bool used[tam];

void DFS(int idx, long long sum = 0) {
    used[idx] = true;
    v[idx] += sum;
    for( int i: G[idx] ) {
        if( !used[i] ) {
            DFS(i, v[idx]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset( v, 0, sizeof v );
    memset( used, 0, sizeof used );
    int n, q, a, b;
    cin >> n >> q;
    for( int i = 0; i < n-1; i++ ) {
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    while( q-- ) {
        cin >> a >> b; a--;
        v[a] += b;
    }
    //cout << "Hello\n";
    DFS(0);
    for( int i = 0; i < n; i++ ) {
        cout << v[i] << ((n == i+1)? '\n' : ' ');
    }
    return 0;
}