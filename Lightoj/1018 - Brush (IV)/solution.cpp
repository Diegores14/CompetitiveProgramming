#include <bits/stdc++.h>
using namespace std;
int n;
const int tam = 17;
int dp[1<<16];
struct point {
    int x, y;
    point(){ x = 0; y = 0; }
};
point a[tam];

bool iscolineal(point A, point B, point C) {
    return (A.y - B.y) * (A.x - C.x) == (A.y - C.y) * (A.x - B.x);
}

int solve(int mask) {
    int &ans = dp[mask];
    if(ans != -1) return ans;
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if((mask&(1<<i)) == 0) cont++;
    }
    if(cont < 2) return cont;
    ans = 1000000000;
    for(int i = 0; i < n; i++) {
        if(((mask>>i)&1) == 0) {
            int temp1 = mask|(1<<i);
            for(int j = 0; j < n; j++) {
                if( (temp1&(1<<j)) == 0) {
                    int temp = temp1|(1<<j);
                    for(int k = 0; k < n; k++) {
                        if(iscolineal(a[i], a[j], a[k])) {
                            temp |= (1<<k);
                        }
                    }
                    ans = min(ans, solve(temp) + 1);
                }
            }
            break;
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << cases << ": " << solve(0) << '\n';
    }
    return 0;
}