#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, r;
    long long ans = 0;
    cin >> n;
    r = n-1;
    vector<int> v(n, 0);
    for(auto &i: v){
        cin >> i;
    }
    for(int i = n-1; i>=0; i--){
        if(v[i]==1){
            ans += r-i;
            r--;
        }
    }
    cout << ans << '\n';
    return 0;
}