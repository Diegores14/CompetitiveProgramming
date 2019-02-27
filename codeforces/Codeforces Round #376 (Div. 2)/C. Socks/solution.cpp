#include <bits/stdc++.h>
using namespace std;
vector<bool> used;
vector<int> colors;
map<int,int> cant;
vector< vector<int> > v;

int DFS(int idx) {
    int tam = 1;
    cant[colors[idx-1]]++;
    used[idx] = true;
    for(int i : v[idx]) {
        if(!used[i]) {
            tam += DFS(i);
        }
    }
    return tam;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, l, r;
    cin >> n >> m >> k;
    used.assign(n+1, false);
    colors.assign(n, 0);
    for(int &i: colors) {
        cin >> i;
    } 
    v.assign(n+1, vector<int>());
    for(int i=0; i<m; i++) {
        cin >> l >> r;
        v[l].emplace_back(r);
        v[r].emplace_back(l);
    }
    long long ans = 0;
    for(int i=1; i<=n; i++) {
        if(!used[i]) {
            cant.clear();
            int total = DFS(i);
            int mmax = 0;
            for(auto &j: cant) {
                mmax = max(j.second, mmax);
            }
            ans += total - mmax;
        }
    }
    cout << ans << '\n';
    return 0;
}