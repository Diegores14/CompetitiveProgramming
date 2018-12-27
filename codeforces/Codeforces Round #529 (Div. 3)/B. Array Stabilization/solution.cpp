#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ans = 1000000000;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    ans = min(ans, v[n-2]-v[0]);
    ans = min(ans, v[n-1]-v[1]);
    cout << ans << '\n';
    return 0;
}