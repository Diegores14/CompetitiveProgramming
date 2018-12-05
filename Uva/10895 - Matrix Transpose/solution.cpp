#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, limit, temp;
    while(cin >> m >> n){
        vector< vector<pair<int,int>> > v(n);
        for(int i=0; i < m; i++){
            cin >> limit;
            vector<int> pos(limit);
            for(int j=0; j < limit; j++){
                cin >> pos[j];
                pos[j]--;
            }
            for(int j = 0; j<limit; j++){
                cin >> temp;
                v[pos[j]].emplace_back(make_pair(i, temp));
            }
        }
        cout << n << ' '  << m << '\n';
        for(int i=0; i<n; i++){
            cout << v[i].size();
            for(int j=0; j<v[i].size(); j++){
                cout << ' ' << v[i][j].first+1;
            }
            cout << '\n';
            for(int j=0; j<v[i].size(); j++){
                cout << (j? " " : "") <<  v[i][j].second;
            }
            cout << '\n';
        }
    }
    return 0;
}