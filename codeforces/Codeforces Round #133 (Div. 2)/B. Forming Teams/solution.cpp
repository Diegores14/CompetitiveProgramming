#include <bits/stdc++.h>
using namespace std;
int used[101];
vector<vector<int>> G;

bool DFS(int idx, int cont) {
    if(used[idx] != -1) {
        return used[idx] == (cont%2);
    }
    bool ans = true;
    used[idx] = cont%2;
    for(int &i: G[idx]) {
        ans = ans && DFS(i, cont+1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    G.assign(101, vector<int>());
    memset(used, -1, sizeof used);
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(used[i] == -1) {
            if(!DFS(i, 0))
                ans++;
        }
    }
    cout << ans + (n-ans)%2 << '\n';
    return 0;
}