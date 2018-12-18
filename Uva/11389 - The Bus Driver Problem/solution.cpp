#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d, r;
    while(cin >> n >> d >> r, n || d || r){
        vector<int> v1(n), v2(n);
        for(int &i: v1)
            cin >> i;
        for(int &i: v2)
            cin >> i;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(v1[i] + v2[n-i-1] - d > 0)ans += (v1[i] + v2[n-i-1] - d) * r;
        }
        cout << ans << '\n';
    }
    return 0;
}