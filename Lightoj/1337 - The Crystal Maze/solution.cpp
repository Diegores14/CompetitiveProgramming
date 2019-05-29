#include <bits/stdc++.h>
using namespace std;
const int tam = 500*500;
int cant[tam], p[tam];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int findSet(int i) { return (i == p[i])? i : p[i] = findSet(p[i]); }

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if(x != y) {
        p[x] = p[y];
        cant[y] += cant[x];
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    int n, m, q;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cout << "Case " << cases << ":\n";
        memset(cant, 0, sizeof cant);
        for(int i=0; i<tam; i++) {
            p[i] = i;
        }
        cin >> n >> m >> q;
        string v[n];
        for(string &i: v) {
            cin >> i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++ ) {
                int tempx = i*m + j;
                if(v[i][j] == 'C') cant[findSet(tempx)]++;
                if(v[i][j] != '#')
                for( int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if( 0 <= x && x < n && 0 <= y && y < m && v[x][y] != '#') {
                        int tempy = x*m + y;
                        unionSet(tempx, tempy);
                    }
                }
            }
        }
        int x, y;
        while(q--) {
            cin >> x >> y;
            x--; y--;
            cout << cant[findSet(x*m+y)] << '\n';
        }
    }
    return 0;
}