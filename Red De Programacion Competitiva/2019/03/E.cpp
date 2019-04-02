#include <bits/stdc++.h>
using namespace std;
vector< string > v(30);
int values[30];
vector< list<pair<int, int> > > G(1000);
int n, m, c;

bool used[31][31];
bool used1[1000];
long long mmin[10000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dx1[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy1[8] = {0, 1, 0, -1, -1, 1, -1, 1};
/*
struct MCMF {
    typedef int ctype;
    enum { MAXN = 1000, INF = INT_MAX; };
    struct Edge { int x, y; ctype cap, cost; }
    vector<Edge> E; vector<int> adj[MAXN];
    MCMF(int NN) : N(NN) {}
    void add(int x, int y, ctype cap, ctype cost) {
        Edge e1 = {x, y, cap, cost}, e2 = {y,x,0,-cost};
        adj[e1.x].push_back(E.size()); E.push_back(e1);
        adj[e2.x].push_back(E.size()); E.push_back(e2);
    }
    void mcmf(int s, int t, ctype &flowVal, ctype &flowCost) {
        int x;
        flowVal = flowCost = 0; memset(phi, 0, sizeof(phi));
        while(true) {
            for( x = 0; x < N; x++) prev[x] = -1;
            for( x = 0; x < N; x++) dist[x] = INF;
            dist[s] = prev[s] = 0;
            set< pair<ctype, int> > Q;
            Q.insert(make_pair(dist[s], s));
            while(!Q.empty()) {
                x = Q.begin()->second; Q.erase(Q.begin());
                for(auto &it: adf[x]) {
                    const Edge &e = E[it];
                    if (e.cap <= 0) continue;
                    ctype cc = e.cost + pi[x] - phi[e.y];
                    if ( dist[x] + cc < dist[e.y] ) {
                        Q.erase(make_pair(dist[e.y], e.y));
                        dist[e.y] = dist[x]  + cc;
                        prev[e.y] = it;
                        Q.insert(make_pair(dist[e.y], e.y));
                    }
                }
            }
            if(prev[t] == -1) break;
            ctype z = INF;
            for( x = t; x != s; x = E[prev[x]].x) 
                { z = min(z, E[prev[x]].cap); }
            for( x = t; x != s; x = E[prev[x]].x)
                { E[prev[x]].cap -= z; E[prev[x]^1].cap += z; }
            flowVal += z;
            flowCost += z * (dist[t] - phi[s] * phi[t]);
            for( x = 0; x < N; x++) 
                { if(prev[x] != -1) phi[x] += dist[x]; }
        }
    }
};
*/

bool checkRange(int a, int b, int c) {
    return a <= b && b < c;
}

void DFS(int x, int y, bool &flag) {
    used[x][y] = true;
    if(!checkRange(1, x, m-1) || !checkRange(1, y, n-1)) {
        flag = true;
        return;
    }
    for(int i=0; i<4; i++) {
        if(!used[x+dx[i]][y+dy[i]]) {
            DFS(x+dx[i], y+dy[i], flag);
        }
    }
}

pair<int, int> createPair(int x, int y) {
    return make_pair(x*n+y, values[v[x][y]-'a']);
}

long long Dijkstra(int ini, int fin) {
    memset(used1, 0, sizeof used1);
    for(int i=0; i<10000; i++) mmin[i] = 1e18;
    set< pair<long long, int> > q;
    q.insert(make_pair(0, ini));
    mmin[997] = 0;
    while(!q.empty() && q.begin()->second != fin) {
        long long dist = q.begin()->first;
        int idx = q.begin()->second;
        used1[idx] = true;
        q.erase(q.begin());
        for(auto &i: G[idx]) {
            if(!used1[i.first] && dist + i.second < mmin[i.first]) {
                q.erase({mmin[i.first], i.first});
                q.insert(make_pair(dist + i.second, i.first));
                mmin[i.first] = dist + i.second;
            }
        }
    }
    if(q.empty()) {
        return 1000000000000;
    }
    return q.begin()->first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> c;
    int x, y;
    for(int i=0; i<m; i++) {
        cin >> v[i];
    }
    for(int i=0; i<c; i++) {
        cin >> values[i];
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(v[i][j] == '.' || v[i][j] == 'B') {
                used[i][j] = false;
            } else {
                used[i][j] = true;
            }
            if(v[i][j] == 'B') {
                x = i; y = j;
            }
        }
    }
    bool flag = false;
    DFS(x, y, flag);
    if(!flag) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == x && j < y) {
                    continue;
                }
                if(v[i][j] != '.' && v[i][j] != 'B')
                    for(int k=0; k<8; k++) {
                        int tempx = i+dx1[k], tempy  = j+dy1[k];
                        if(checkRange(0, tempx, m) && checkRange(0, tempy, n) &&
                            v[tempx][tempy] != '.' && v[tempx][tempy] != 'B') {
                                G[i*n+j].push_back(createPair(tempx, tempy));
                        }
                    }
            }
        }
        for(int i=0; i < y; i++) {
            //G[997].push_back(createPair(x, i));
            if(v[x][i] != '.' && v[x][i] != 'B')
                for(int j: {-1, 0, 1}) {
                    if(checkRange(0, x-1, m) && checkRange(0, j+i, y+1) &&
                        v[x-1][j+i] != '.' && v[x-1][j+i] != 'B') {
                        G[x*n+i].push_back(createPair(x-1, i+j));
                    }
                    if(checkRange(0, x+1, m) && checkRange(0, j+i, y+1) &&
                        v[x+1][j+i] != '.' && v[x+1][j+i] != 'B') {
                        G[(x+1)*n+i+j].push_back(make_pair(950+i, 0));
                    }
                }
        }
        long long ans = 1e18;
        for(int i=0; i<y; i++) {
            ans = min(ans, Dijkstra(x*n+i, 950+i) + values[v[x][i]-'a']);
        }
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}