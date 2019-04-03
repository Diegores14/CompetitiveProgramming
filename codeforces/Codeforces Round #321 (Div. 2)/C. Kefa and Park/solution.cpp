#include <bits/stdc++.h>
using namespace std;
bool used[1000000];
int cats[1000000];
vector< list<int> > G;
int n, m;

int DFS(int idx, int cant) {
    used[idx] = true;
    if( cant + cats[idx] > m ) {
        return 0;
    }
    int ans = 0;
    bool flag = true;
    for(int &i: G[idx]) {
        if(!used[i]) {
            flag = false;
            ans += DFS(i, (cats[idx]? cant + 1 : 0));
        }
    }
    return flag? 1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> n >> m;
    memset(used, 0, sizeof used);
    G.assign(n, list<int>());
    for(int i=0; i<n; i++) {
        cin >> cats[i];
    }
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << DFS(0, 0) << '\n';
    return 0;
}