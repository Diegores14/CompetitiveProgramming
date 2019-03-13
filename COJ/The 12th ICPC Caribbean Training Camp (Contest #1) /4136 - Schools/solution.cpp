#include <bits/stdc++.h>
using namespace std;

struct MCMF {
    typedef int ctype;
    enum { MAXN = 1000, INF = INT_MAX };
    struct Edge { int x, y; ctype cap, cost; };
    vector<Edge> E; vector< int > adj[MAXN];
    int N, prev[MAXN]; ctype dist[MAXN], phi[MAXN];
    MCMF(int NN): N(NN) {}
    void add(int x, int y, ctype cap, ctype cost) {
        Edge e1 = {x, y, cap, cost}, e2 = {y, x, 0, -cost};
        adj[e1.x].push_back( E.size() ); E.push_back(e1);
        adj[e2.x].push_back( E.size() ); E.push_back(e2);
    }
    void mcmf(int s, int t, ctype &flowVal, ctype &flowCost) {
        int x;
        flowVal = flowCost = 0; memset(phi, 0, sizeof(phi));
        while (true) {
            for (x = 0; x < N; x++) prev[x] = -1;
            for (x = 0; x < N; x++) dist[x] = INF;
            dist[s] = prev[s] = 0;
            set< pair<ctype, int> > Q;
            Q.insert(make_pair(dist[s], s));
            while (!Q.empty()) {
                x = Q.begin()->second; Q.erase(Q.begin());
                for(auto &it: adj[x]) {
                    const Edge &e = E[it];
                    if (e.cap <= 0) continue;
                    ctype cc = e.cost + phi[x] - phi[e.y];
                    if (dist[x] + cc < dist[e.y]) {
                        Q.erase(make_pair(dist[e.y], e.y));
                        dist[e.y] = dist[x] + cc;
                        prev[e.y] =  it;
                        Q.insert(make_pair(dist[e.y], e.y));
                    }
                }
            }
            if (prev[t] == -1) break;
            ctype z = INF;
            for (x = t; x != s; x = E[prev[x]].x)
                { z = min(z, E[prev[x]].cap); }
            for(x = t; x != s; x = E[prev[x]].x) 
                { E[prev[x]].cap -= z; E[prev[x]^1].cap += z; }
            flowVal += z;
            flowCost += z * (dist[t] - phi[s] + phi[t]);
            for (x = 0; x < N; x++) 
                { if (prev[x] != -1) phi[x] += dist[x]; }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, m, a, b, k; 
    cin >> n;
    MCMF f(2*n+2);
    int t = 2*n+1;
    for(int i=1; i<=n; i++) {
        f.add(0, i, 1, 0);
        f.add(n+i, t, 1, 0);
    }
    for(int i=1; i<=n; i++) {
        cin >> m >> a >> b >> k;
        for(int j = a; j <= b; j++) {
            f.add(i, abs(n+j), 1, k*abs(j-m));
        }
    }
    int flujo = 0, cost = 0;
    f.mcmf(0, t, flujo, cost);
    if(flujo == n) {
        cout << cost << '\n';
    } else {
        cout << "NIE\n";
    }
    return 0;
}