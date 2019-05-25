#include <bits/stdc++.h>
using namespace std;
const int tam = 200005;
bool used[tam];

void DFS(int idx, int &x, int &y, vector< list<int> > &G, int prof = 0) {
    used[idx] = true;
    if(prof&1) x++;
    else y++;
    for(int i: G[idx]) {
        if(!used[i]) {
            DFS(i, x, y, G, prof+1);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, u, v;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n;
        set<int> num;
        vector< list<int> > G(tam);
        for(int i = 0; i < n; i++) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            num.insert(u);
            num.insert(v);
        }
        memset(used, 0, sizeof used);
        int ans = 0;
        for(int i: num) {
            if(!used[i]) {
                int x = 0, y = 0;
                DFS(i, x, y, G);
                ans += max(x, y);
            }
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}