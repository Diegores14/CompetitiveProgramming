#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ans(n+1);
    vector<pair<int,int>> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i].first >> v[i].second;
    }
    if(n !=3){
        for(int i=1; i<=n; i++){
            if(ans[v[i].first] == 0 && (v[v[i].first].first == v[i].second || v[v[i].first].second == v[i].second)){
                ans[v[i].first] = v[i].second;
            }else{
                ans[v[i].second] = v[i].first;
            }
        }
        cout << ans[1];
        int i = ans[1];
        while(i != 1){
            cout << ' ' << ans[i];
            i = ans[i];
        }
    }else{
        cout << "1 2 3";
    }
    cout << '\n';
    return 0;
}