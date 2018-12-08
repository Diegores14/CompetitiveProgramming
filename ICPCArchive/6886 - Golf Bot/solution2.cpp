#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp;
    while(cin >> n){
        int ans = 0;
        vector<bool> v(200005, false);
        for(int i = 0; i<n; i++){
            cin >> temp;
            v[temp] = true;
        }
        cin >> m;
        for(int i=0; i < m; i++){
            cin >> temp;
            if(v[temp]){
                ans++;
            }else{
                for(int j = 1; j < temp; j++){
                    if(v[j] && v[temp - j]){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}