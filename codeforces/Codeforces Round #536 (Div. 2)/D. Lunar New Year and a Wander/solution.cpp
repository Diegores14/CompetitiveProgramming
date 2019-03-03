#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    vector<bool> used(n+1, false);
    vector< vector<int> > G(n+1);
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(1);
    used[1] = true;
    vector<int> ans;
    while(!q.empty()) {
        int temp = q.top();
        q.pop();
        ans.emplace_back(temp);
        for(int &i: G[temp]) {
            if(!used[i]) {
                used[i] = true;
                q.push(i);
            }
        }
    }
    for ( int i=0; i < n; i++ ) {
        cout << ans[i] << ( (i == n-1)? '\n' : ' ');
    }
    return 0;
}