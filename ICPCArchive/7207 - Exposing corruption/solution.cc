#include <bits/stdc++.h>
using namespace std;
int D, P, R, B;
const int tam = 205, limit = 1e4+5;
int p[tam], cant[tam][2], cost[tam];
int len;
int dp[tam][limit];

int findSet( int i ) { return i == p[i]? i: p[i] = findSet( p[i] ); }

void unionSet( int i, int j ) {
    int x = findSet(i), y = findSet(j);
    if( x != y ) {
        p[x] = y;                           // Y is parent.
        cost[y] += cost[x];
        cant[y][0] += cant[x][0];
        cant[y][1] += cant[x][1];
    }
}

int solve( int idx, int budget, int par ) {
    if( idx == len ) return 0;
    int &ans = dp[idx][budget];
    if( ans != -1 ) return ans;
    ans = solve( idx+1, budget, par ) + cant[idx][par];
    if( budget - cost[idx] >= 0 ) {
        ans = max( ans, solve(idx+1, budget - cost[idx], par) + cant[idx][par^1] );
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y;
    //cout << "Solution\n";
    while( cin >> D >> P >> R >> B ) {
        len = 0; 
        for( int i = 0; i < D; i++ ) {
            cin >> cost[i];
            cant[i][0] = 1;
            cant[i][1] = 0;
            p[i] = i;
        }
        for( int i = D; i < D+P; i++ ) {
            cin >> cost[i];
            cant[i][1] = 1;
            cant[i][0] = 0;
            p[i] = i;
        }
        for( int i = 0; i < R; i++ ) {
            cin >> x >> y; x--; y--;
            unionSet(x, D+y);
        }
        bool used[D+P];
        memset( used, 0, sizeof used );
        for( int i = 0; i < D+P; i++ ) {
            int temp = findSet(i);
            if( !used[ temp ] ) {
                used[ temp ] = true;
                cant[len][0] = cant[temp][0];
                cant[len][1] = cant[temp][1];
                cost[len] = cost[temp];
                //cout << cant[len][0] << ' ' << cant[len][1] << ' ' << cost[len] << '\n';
                len++;
            }
        }
        memset( dp, -1, sizeof dp );
        cout << solve( 0, B, 0) << ' ';
        memset( dp, -1, sizeof dp );
        cout << solve( 0, B, 1) << '\n';
    }
    return 0;
}