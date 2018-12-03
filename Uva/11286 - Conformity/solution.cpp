#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(5);
    int n;
    while(cin >> n, n){
        int mmax = 0;
        int ans = 0;
        map<vector<int>, int> m;
        for(int i = 0; i < n; i++){
            cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
            sort(v.begin(), v.end());
            m[v]++;            
        }
        for(auto i : m){
            mmax = max(mmax, i.second);
        }
        for(auto i : m){
            if(i.second == mmax)
                ans += mmax;
        }
        cout << ans << '\n';
    }
    return 0;
}