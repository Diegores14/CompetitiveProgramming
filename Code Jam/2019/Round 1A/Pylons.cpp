#include <bits/stdc++.h>
using namespace std;
bool used[20][20];
int n, m;
int tam;
int ans[2][405];

bool solve(int idx, int x, int y) {
    if(idx == tam) {
        ans[0][idx] = x;
        ans[1][idx] = y;
        return true;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!used[i][j] && i != x && j != y && x-y != i-j && x+y != i+j) {
                used[i][j] = true;
                if(solve(idx+1, i, j)) {
                    ans[0][idx] = x;
                    ans[1][idx] = y;
                    return true;
                } else {
                    used[i][j] = false;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case #" << k << ": ";
        cin >> n >> m;
        tam = n*m;
        memset(used, 0, sizeof used);
        if(solve(0, n+1, 40000)) {
            cout << "POSSIBLE\n";
            for(int i=1; i<=tam; i++) {
                cout << ans[0][i]+1 << ' ' << ans[1][i]+1 << '\n';
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}