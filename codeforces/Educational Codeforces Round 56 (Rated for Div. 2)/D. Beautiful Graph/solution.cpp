#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
vector<int> v;

long long potentation(long long a, long long b){
    long long ans = 1, temp = a;
    while(b){
        if(b&1){
            ans = (ans * temp%M)%M;
        }
        b >>= 1;
        temp = (temp * a%M)%M;
    }
    return ans;
}

long long BFS(vector<vector<int>> &G, int idx){
    int color[2];
    color[0] = color[1] = 0;
    queue<int> q;
    if(v[idx] == -1){
        q.push(idx);
        v[idx] = 1;
        while(!q.empty()){
            int temp = q.front();
            color[v[temp]-1]++;
            q.pop();
            for(int i : G[temp]){
                if(v[i] == -1){
                    q.push(i);
                    v[i] = (v[temp] == 1)? 2 : 1;
                }else{
                    if(v[temp] == v[i])
                        return 0;
                }
            }
        }
        if(color[1] == 0){
            return 3;
        }
        return (potentation(2, color[0]) + potentation(2, color[1]))%M;
    }else{
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, a, b;
    cin >> t;
    while(t--){
        long long ans = 1;
        cin >> n >> m;
        vector<vector<int>> G(n);
        for(int i=0; i<m; i++){
            cin >> a >> b;
            a--; b--;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }
        v.assign(G.size(), -1);
        for(int i=0; i<G.size(); i++)
            ans = (ans * BFS(G, i))%M;
        cout << ans << '\n';
    }
    return 0;
}