#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    bool sal = false;
    while(cin >> n, n){
        if(sal){
            cout << '\n';
        }else{
            sal = true;
        }
        int temp;
        int ans = 0;
        map<int,int> m;
        for(int i = 0; i<n; i++){
            cin >> temp;
            m[temp]++;
            ans = max(ans, m[temp]);
        }
        vector<vector<int>> v(ans);
        int limit = n/ans + ( n%ans? 1 : 0);
        int k=0;
        cout << ans << '\n';
        for(auto &i: m){
            while(i.second){
                if(k == ans)
                    k = 0;
                v[k].push_back(i.first);
                i.second--;
                k++;
            }
        }
        for(auto &i: v){
            int k = 0;
            for(int &j: i){
                if(k)
                    cout << ' ';
                cout << j;
                k++;
            }
            cout << '\n';
        }
    }
    return 0;
}