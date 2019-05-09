#include <bits/stdc++.h>
using namespace std;
typedef vector< vector < pair<int, int> > > Graph;
long long dp[10005][2];
bool used[10005];

void dijkstra(int idx, Graph &G, int j) {
    set< pair<int, int> > q;
    q.insert({0, idx});
    dp[idx][j] = 0;
    while(!q.empty()) {
        auto temp = *q.begin();
        //cout << j << ' ' << temp.second << ' ' << temp.first << '\n';
        q.erase(q.begin());
        used[temp.second] = true;
        for(auto &i: G[temp.second]) {
            if(!used[i.first] && temp.first + i.second < dp[i.first][j]) {
                q.erase({dp[i.first][j], i.first});
                dp[i.first][j] = temp.first + i.second;
                q.insert({dp[i.first][j], i.first});
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T, s, t, n, m, v, u, c, p; 
    cin >> T;
    for(int r = 1; r <= T; r++) {
        cout << "Case " << r << ": ";
        cin >> n >> m >> s >> t >> p;
        Graph G(n+1), GT(n+1);
        int ans = -1;
        for(int i=0; i<m ; i++) {
            cin >> u >> v >> c;
            G[u].push_back({v, c});
            GT[v].push_back({u, c});
        }
        for(int i=0; i<10005; i++) {
            dp[i][0] = dp[i][1] = 2e9;
        }
        memset(used, 0, sizeof used);
        dijkstra(s, G, 0);
        memset(used, 0, sizeof used);
        dijkstra(t, GT, 1);
        //cout << n << ' ' << m << ' ' << s << ' ' << t << p << '\n';
        for(int i=1; i <= n; i++) {
            for(auto &j: G[i]) {
                if(dp[i][0] + j.second + dp[j.first][1] <= p) {
                    ans = max(ans, j.second);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}