#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        for(int &i: v){
            cin >> i;
        }
        long long ans = 0; 
        for(int i=1; i<n; i++){
            for(int j=0; j < i; j++){
                if(v[j] <= v[i])
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}