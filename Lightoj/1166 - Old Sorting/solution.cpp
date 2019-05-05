#include <bits/stdc++.h>
using namespace std;
bool used[105];
int v[105];

int DFS(int idx, int cant = 0) {
    if(used[idx]) return cant - 1;
    used[idx] = true;
    return DFS(v[idx], cant+1);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cout << "Case " << r << ": ";
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> v[i];
            v[i]--;
        }
        int ans = 0;
        memset(used, 0, sizeof used);
        for(int i=0; i<n; i++) {
            if(!used[i])
                ans += DFS(i);
        }
        cout << ans << '\n';
    }
    return 0;
}