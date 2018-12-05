#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class DisjoinSet{
    vi parent;
    public:
    DisjoinSet(int N){
        parent.assign(N, 0);
        for(int i=0; i<N; i++){
            parent[i] = i;
        }
    }
    int findSet(int i){ return parent[i] = ((parent[i] == i)? i : findSet(parent[i])); }
    bool isSame(int j, int i){
        return findSet(i) == findSet(j);
    }
    void UnionSet(int i, int j){
        if(!isSame(i, j)){
            int x = findSet(i), y = findSet(j);
            parent[x] = y;
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, a, b;
    char c;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        cin.ignore();
        DisjoinSet ds(n);
        int ans1 = 0, ans2 = 0;
        while(getline(cin, s), s != ""){
            stringstream in;
            in << s;
            in >> c >> a >> b;
            if(c == 'c'){
                ds.UnionSet(a-1, b-1);
            }else{
                if(ds.isSame(a-1, b-1))
                    ans1++;
                else
                    ans2++;
            }
        }
        cout << ans1 << ',' << ans2 << '\n';
        if(t)
            cout << '\n';
    }
    return 0;
}