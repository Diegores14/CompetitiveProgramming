#include <bits/stdc++.h>
using namespace std;
vector< list<int> > G;
bool used[100005];
long long cant = 0, sum = 0;

long double DFS(int idx, int p) {
    long double ans = 0;
    for(int &i: G[idx]) {
        if(i != p) {
            ans += DFS(i, idx) + 1;
        }
    }
    if(ans)
        return ans/(G[idx].size() - (p != 0));
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, u, v;
    cin >> n;
    G.assign(n+1, list<int>());
    memset(used, 0, sizeof used);
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << fixed << setprecision(15) << DFS(1, 0) << '\n';
    return 0;
}