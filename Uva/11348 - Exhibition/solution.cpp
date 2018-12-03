#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k, n, m, aux;
    cout << fixed << setprecision(6);
    cin >> k;
    for(int r=1; r<=k; r++){
        cin >> n;
        map<int, int> stamps;
        set<int> s[n];
        vector<int> ans(n, 0);
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> m;
            for(int j=0; j<m; j++){
                cin >> aux;
                s[i].insert(aux);
            }
            for(auto j : s[i]){
                stamps[j]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j: s[i]){
                if(stamps[j] == 1){
                    total++;
                    ans[i]++;
                }
            }
        }
        cout << "Case " << r << ':';
        for(int i: ans){
            cout << " " << double(i*100)/total << "%";
        }
        cout << '\n';
    }
    return 0;
}