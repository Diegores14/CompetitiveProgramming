#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int v[n];
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        long long sum = v[0];
        int ans = 1;
        for(int i=1; i<n-1; i++){
            if(sum + v[i] < v[i+1]){
                ans++;
                sum +=v[i];
            }
        }
        cout << ans+1 << '\n';
    }
    return 0;
}