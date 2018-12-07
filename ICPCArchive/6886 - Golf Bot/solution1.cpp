#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp;
    while(cin >> n){
        int ans = 0;
        set<int> s;
        for(int i = 0; i<n; i++){
            cin >> temp;
            s.insert(temp);
        }
        cin >> m;
        for(int i=0; i < m; i++){
            cin >> temp;
            if(s.count(temp)){
                ans ++;
            }else{
                for(int i: s){
                    if(temp - i < 0){
                        break;
                    }
                    if(s.count(temp - i)){
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