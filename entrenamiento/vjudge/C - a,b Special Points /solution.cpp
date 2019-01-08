#include <bits/stdc++.h>
using namespace std;
typedef vector< int > vi; 

class UnionFind {
    private:
        vi p;
    public:
    UnionFind(int N){
        p.assign(N+1, 0);
        for(int i=0; i<=N; i++){
            p[i] = i;
        }
    }
    int findSet(int i) { return (i == p[i])? i : p[i] = findSet(p[i]); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void UnionSet(int i, int j){
        if( !isSameSet(i, j) ) {
            int x = findSet(i), y = findSet(j);
            p[x] = y;
        }
    }
};

int main (){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a, b, u, v;
    cin >> n >> m >> a >> b;
    vi adj(n+1, 0);
    UnionFind uf(n);
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u]++;
        adj[v]++;
        uf.UnionSet(u, v);
    }
    vector< long long > mmin(n+1, 1e15), mmax(n+1, 0);
    for(int i=1; i<=n; i++) {
        int x = uf.findSet(i);
        mmin[x] = min(mmin[x], 1LL * a * adj[i]);
        mmax[x] = max(mmax[x], 1LL * b * adj[i]);
    }
    long long ans = 0;
    for(int i=1; i<=n; i++) {
        int x = uf.findSet(i);
        if(mmin[x] < adj[i] && adj[i] < mmax[x]) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}