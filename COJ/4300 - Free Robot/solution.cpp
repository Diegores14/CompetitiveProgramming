#include <bits/stdc++.h>
using namespace std;
//long long dp[15][15][15];
bool used[15][15];
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {0, 1, -1, -1, 0, -1, 1, 1};

long long solve(int x, int y, int t, int &n) {
    if(t == n) return 1;
    // long long &ans = dp[x][y][t];
    // if(ans != -1) return ans;
    long long ans = 0;
    for(int i = 0; i < 8; i++) {
        if( x + dx[i] < 0 || n < x + dx[i] )
            continue;
        if( y + dy[i] < 0 || n < y + dy[i] )
            continue;
        if(used[x + dx[i]][y + dy[i]])
            continue;
        used[x + dx[i]][y + dy[i]] = true;
        ans += solve(x + dx[i], y + dy[i], t+1, n);
        used[x + dx[i]][y + dy[i]] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long answer[14] = {3, 15, 75, 391, 2065, 11091, 60215, 330003, 1820869, 10103153, 
                    56313047, 315071801, 1768489771, 9953853677};
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        // memset(used, 0, sizeof used);
        // used[0][0] = true;
        cout << answer[n-1] << '\n';
    }
    return 0;
}