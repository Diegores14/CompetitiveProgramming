#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > pii;
bool used[500];
int ans[500];

int Dijkstra(int idx, vector< vector < pii > > &G) {
    set< pii > q;
    q.insert({0, idx});
    ans[idx] = 0;
    while(!q.empty()) {
        auto temp = *q.begin();
        q.erase(temp);
        used[temp.second] = true;
        for(auto &i: G[temp.second]) {
            if(!used[i.first] && ans[i.first] > max(ans[temp.second], i.second)) {
                q.erase({ans[i.first], i.first});
                ans[i.first] = max(ans[temp.second], i.second);
                q.insert({ans[i.first], i.first});
            }
        }
    }
}

int main() {
    int t, n, m, a, b, c;
    scanf("%d", &t);
    for(int k=1; k <= t; k++) {
        printf("Case %d:\n", k);
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            ans[i] = 1000000000;
        }
        vector< vector < pii > > G(n);
        for( int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, c));
        }
        scanf("%d", &a);
        for(int i=0; i<n; i++) {
            ans[i] = 1000000000;
        }
        memset(used, 0, sizeof used);
        Dijkstra(a, G);
        for(int i=0; i<n; i++) {
            if(ans[i] != 1000000000)
                printf("%d\n", ans[i]);
            else {
                printf("Impossible\n");
            }
        }
    }
    return 0;
}