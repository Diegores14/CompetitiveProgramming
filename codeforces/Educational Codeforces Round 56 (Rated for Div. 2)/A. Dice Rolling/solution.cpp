#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, x;
    cin >> t;
    while(t--){
        cin >> x;
        int ans = 0;
        while(x>0){
            x -= 7;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}