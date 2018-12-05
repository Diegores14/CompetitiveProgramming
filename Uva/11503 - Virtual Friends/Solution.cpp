#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind{
    private: vi p, rank;
    public:
        UnionFind(int n){
            p.assign(n, 0);
            rank.assign(n, 1);
            for(int i = 0; i<n; i++){
                p[i] = i;
            }
        }
        int findSet(int i){ return p[i] == i ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
        int UnionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                p[x] = y;
                rank[y] += rank[x];
            }
            return rank[findSet(i)];
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n; 
    string s1, s2;
    cin >> t;
    while(t--){
        cin >> n;
        UnionFind uf((n<<1) + 1);
        map<string, int> m;
        for(int i=0; i<n; i++){
            cin >> s1 >> s2;
            if(m.count(s1) == 0)
                m[s1] = m.size();
            if(m.count(s2) == 0)
                m[s2] = m.size();
            cout << uf.UnionSet(m[s1], m[s2]) << '\n';
        }
    }
    return 0;
}