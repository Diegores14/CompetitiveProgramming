#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int mmin[101];
bool used[101];
int n;

void dijkstra(vector< list<ii> > &G) {
    set< ii >  q;
    q.insert({0, 1});
    mmin[1] = 0;
    while(!q.empty() && q.begin()->second != n) {
        int x = q.begin()->first;
        int y = q.begin()->second;
        q.erase(q.begin());
        used[y] = true;
        for(auto i: G[y]) {
            if(!used[i.first] && x + i.second < mmin[i.first]) {
                q.erase({mmin[i.first], i.first});
                mmin[i.first] = x + i.second;
                q.insert({mmin[i.first], i.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, t, a, b, w;
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++) {
            mmin[i] = 1000000000;
        }
        memset(used, 0, sizeof used);
        vector< list<ii> > G(n+1);
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }
        dijkstra(G);
        if(mmin[n] != 1000000000)
            cout << "Case " << r << ": " << mmin[n] << '\n';
        else
            cout << "Case " << r << ": Impossible\n";
    }
    return 0;
}