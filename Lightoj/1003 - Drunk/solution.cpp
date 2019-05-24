#include <bits/stdc++.h>
using namespace std;
bool used[10005];
int timeEnd[10005];
int tam;

void DFS1(int idx, vector< list<int> > &G) {
    used[idx] = true;
    for(int i : G[idx]) {
        if(!used[i])
            DFS1(i,G);
    }
    timeEnd[tam++] = idx;
}

int DFS2(int idx, vector< list<int> > &G, int pro = 1) {
    used[idx] = true;
    int ans = pro;
    for(int i : G[idx]) {
        if(!used[i])
            ans += DFS2(i, G, pro+1);
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    string s1, s2;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        tam = 0;
        map<string, int> m;
        vector< list<int> > G(10001), GT(10001);
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if(m.count(s1) == 0) {
                m[s1] = m.size();
            } 
            if(m.count(s2) == 0) {
                m[s2] = m.size();
            } 
            G[m[s1]].push_back(m[s2]);
            GT[m[s2]].push_back(m[s1]);
        }
        memset(used, 0, sizeof used);
        for(int i = 0; i < m.size(); i++) {
            if(!used[i]) {
                DFS1(i, G);
            }
        }
        reverse(timeEnd, timeEnd + m.size());
        bool ans = false;
        memset(used, 0, sizeof used);
        for(int i = 0; i < m.size(); i++) {
            if(!used[timeEnd[i]]) {
                ans |= (DFS2(timeEnd[i], GT) != 1);
            }
        }
        cout << "Case " << cases << ": " << (ans? "No" : "Yes") << '\n';
    }
    return 0;
}