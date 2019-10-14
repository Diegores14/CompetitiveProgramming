#include <bits/stdc++.h>
using namespace std;
double dp[15][15][15][15][5][5];
bool used[15][15][15][15][5][5];
int C, D, H, S;

double solveDP( int c, int d, int h, int s, int j1, int j2 ) {
    int cc = c + (j1 == 1) + (j2 == 1);
    int dd = d + (j1 == 2) + (j2 == 2);
    int hh = h + (j1 == 3) + (j2 == 3);
    int ss = s + (j1 == 4) + (j2 == 4);
    if( cc >= C && dd >= D && hh >= H && ss >= S) return 0;
    if( cc + dd + hh + ss == 54 ) return 1e18;
    if( used[c][d][h][s][j1][j2] ) return dp[c][d][h][s][j1][j2];
    double &ans = dp[c][d][h][s][j1][j2];
    used[c][d][h][s][j1][j2] = true;
    ans = 0;
    if( c < 13 ) {
        ans += (13-c)*(1 + solveDP( c+1, d, h, s, j1, j2 ) );
    }
    if( d < 13 ) {
        ans += (13-d)*(1 + solveDP( c, d+1, h, s, j1, j2 ) );
    }
    if( h < 13 ) {
        ans += (13-h)*(1 + solveDP( c, d, h+1, s, j1, j2 ) );
    }
    if( s < 13 ) {
        ans += (13-s)*(1 + solveDP( c, d, h, s+1, j1, j2 ) );
    }
    if( j1 == 0 ) {
        double temp = solveDP(c, d, h, s, 1, j2);
        temp = min( temp, solveDP(c, d, h, s, 2, j2) );
        temp = min( temp, solveDP(c, d, h, s, 3, j2) );
        temp = min( temp, solveDP(c, d, h, s, 4, j2) );
        ans += 1+temp;
    }
    if( j2 == 0 ) {
        double temp = solveDP(c, d, h, s, j1, 1);
        temp = min( temp, solveDP(c, d, h, s, j1, 2) );
        temp = min( temp, solveDP(c, d, h, s, j1, 3) );
        temp = min( temp, solveDP(c, d, h, s, j1, 4) );
        ans += 1+temp;
    }
    ans /= (54-(cc+dd+hh+ss));
    return ans;
}

bool isValid( ) {
    int sum = 0;
    if( C > 13 ) sum += C-13;
    if( D > 13 ) sum += D-13;
    if( H > 13 ) sum += H-13;
    if( S > 13 ) sum += S-13;
    return sum <= 2;
}

void solve() {
    memset( used, 0, sizeof used );
    cin >> C >> D >> H >> S;
    if( !isValid() ) {
        cout << -1 << '\n';
        return;
    }
    cout << solveDP(0,0,0,0,0,0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}