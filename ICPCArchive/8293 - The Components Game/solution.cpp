#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> p;
    public:
        UnionFind(int n) {
            p.assign(n, 0);
            for(int i=0; i<n; i++) {
                p[i] = i;
            }
        }
        int findSet(int i) { return (i == p[i])? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        bool unionSet(int i, int j) {
            if(!isSameSet(i, j) ) {
                int x = findSet(i),  y = findSet(j);
                p[x] = y;
                return true;
            }
            return false;
        }
};

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, n, m, k;
    char c;
    cin >> p;
    while(p--) {
        cin >> k >> n >> m;
        vector< vector<int> > v(n, vector<int> (m, 0) );
        for(auto &i: v) {
            for(int &j: i) {
                cin >> c;
                j = c-'0';
            }
        }
        int tam = n*m, color[2] = {0 , 0};
        vector< vector<UnionFind> > st(2, vector<UnionFind>(2, UnionFind(tam)));
        vector< vector<int> > prefix(2, vector<int> (m, 0));
        vector< vector<int> > suffix(2, vector<int> (m, 0));
        for(int j=0; j<m-1; j++) {
            for(int i=0; i<n; i++) {
                color[v[i][j]]++;
                if(i > 0) {
                    if(v[i][j] == v[i-1][j]) {
                        int l = i*m + j;
                        if( st[0][v[i][j]].unionSet(l, l-m) ) {
                            color[v[i][j]]--;
                        }
                    }
                }
                if(j > 0) {
                    if(v[i][j] == v[i][j-1]) {
                        int l = i*m + j;
                        if( st[0][v[i][j]].unionSet(l, l-1) ) {
                            color[v[i][j]]--;
                        }
                    }
                }
            }
            prefix[0][j+1] = color[0];
            prefix[1][j+1] = color[1];
        }
        color[0] = color[1] = 0;
        for(int j=m-1; j>0; j--) {
            for(int i=0; i<n; i++) {
                color[v[i][j]]++;
                if(i > 0) {
                    if(v[i][j] == v[i-1][j]) {
                        int l = i*m + j;
                        if( st[1][v[i][j]].unionSet(l, l-m) ) {
                            color[v[i][j]]--;
                        }
                    }
                }
                if(j < m-1) {
                    if(v[i][j] == v[i][j+1]) {
                        int l = i*m + j;
                        if( st[1][v[i][j]].unionSet(l, l+1) ) {
                            color[v[i][j]]--;
                        }
                    }
                }
            }
            suffix[0][j-1] = color[0];
            suffix[1][j-1] = color[1];
        }
        int ans[2] = {-1, -1};
        for(int i=0; i<n; i++) {
            if(prefix[0][i] + suffix[0][i] > ans[0]) {
                ans[0] = prefix[0][i] + suffix[0][i];
                ans[1] = prefix[1][i] + suffix[1][i];
                continue;
            }
            if(prefix[0][i] + suffix[0][i] == ans[0] && 
                ans[1] < prefix[1][i] + suffix[1][i]) {
                ans[1] = prefix[1][i] + suffix[1][i];
            }
        }
        cout << k << ans[0] << ans[1];
    }
    return 0;
}