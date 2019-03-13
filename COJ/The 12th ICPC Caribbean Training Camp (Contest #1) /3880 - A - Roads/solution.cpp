#include <bits/stdc++.h>
using namespace std;
int timeEnd[10007];
int tiempo = 0;
int comp = 0;
bool used[10007];
int idComp[10007];
int sonComp[10007];
vector< vector<int> > G;
vector< vector<int> > GT;

void DFS(int idx) {
    used[idx] = true;
    for(int &i: G[idx]) {
        if(!used[i]) {
            DFS(i);
        }
    }
    timeEnd[tiempo++] = idx;
}

void DFS1(int idx) {
    used[idx] = true;
    idComp[idx] = comp;
    for(int &i: GT[idx]) {
        if(!used[i]) {
            DFS1(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(timeEnd, 0, sizeof timeEnd);
    memset(sonComp, 0, sizeof sonComp);
    int n, m, a, b;
    cin >> n >> m;
    G.assign(n, vector<int>());
    GT.assign(n, vector<int>());
    vector< pair<int, int> > edge(m);
    for(auto &i: edge) {
        cin >> i.first >> i.second;
        G[--i.first].emplace_back(--i.second);
        GT[i.second].emplace_back(i.first);
    }
    memset(used, 0, sizeof used);
    for(int i = 0; i<n; i++) {
        if(!used[i]) {
            DFS(i);
        }
    }
    reverse(timeEnd, timeEnd+n);
    memset(used, 0, sizeof used);
    for(int i = 0; i<n; i++) {
        if(!used[timeEnd[i]]) {
            DFS1(timeEnd[i]);
            comp++;
        }
    }
    memset(used, 0, sizeof used);
    for(auto &i: edge) {
        if(idComp[i.first] != idComp[i.second]) {
            sonComp[idComp[i.first]]++;
            used[idComp[i.second]] = true;
        }
    }
    int cantRoot = 0;
    for(int i = 0; i<comp; i++) {
        if(!used[i]) {
            cantRoot++;
        }
    }
    int ans = 0;
    if(comp > 1) {
        for(int i=0; i<comp; i++) {
            if(sonComp[i] == 0) {
                ans++;
            }
        }
        //cout << cantRoot << '\n';
        ans += max(0, cantRoot - ans);
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}