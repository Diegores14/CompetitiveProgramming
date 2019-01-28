#include <bits/stdc++.h>
using namespace std;
int n, m, s, d, u, v, p;
vector<int> used;
int shortpath[500][500];

void dijkstra(vector< list < pair<int, int > > > &G) {
    priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        pair<int, int> curr = q.top();
        q.pop();
        if(used[curr.second] == -1) {
            used[curr.second] = curr.first;
            for(auto &i: G[curr.second] ) {
                if(used[i.first] == -1)
                    q.push(make_pair(curr.first + i.second, i.first));
            }
        }
    }
}

void fillShortpath(vector< list< pair<int, int> > > &G) {
    queue< int > q;
    q.push(d);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto &i: G[curr]) {
            if(used[curr] == used[i.first] + i.second) {
                shortpath[i.first][curr] = 1;
                q.push(i.first);
            }
        }
    }
}

int dijkstra2(vector< list< pair< int, int> > > &G ) {
    priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty() && q.top().second != d) {
        pair<int, int> curr = q.top();
        q.pop();
        if(used[curr.second] == -1) {
            used[curr.second] = curr.first;
            for(auto &i: G[curr.second] ) {
                if(used[i.first] == -1 && shortpath[curr.second][i.first] == 0)
                    q.push(make_pair(curr.first + i.second, i.first));
            }
        }
    }
    if(q.empty()) {
        return -1;
    } else {
        return q.top().first;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<int> q;
    while(cin >> n >> m, n || m) {
        cin >> s >> d;
        vector< list< pair<int, int> > > G(n);
        vector< list< pair<int, int> > > GT(n);
        for(int i=0; i<m; i++) {
            cin >> u >> v >> p;
            G[u].push_back(make_pair(v, p));
            GT[v].push_back(make_pair(u, p));
        }
        used.assign(n, -1);
        dijkstra(G);
        /*for(int &i: used) {
            cout << i << ' ';
        }
        cout << '\n';*/
        memset(shortpath, 0, sizeof shortpath);
        fillShortpath(GT);
        /*for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << shortpath[i][j] << ' ';
            }
            cout << '\n';
        }*/
        used.assign(n, -1);
        cout << dijkstra2(G) << '\n';
    }
    return 0;
}