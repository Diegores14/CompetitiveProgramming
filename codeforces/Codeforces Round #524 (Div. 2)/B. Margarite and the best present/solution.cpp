#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    long long l, r;
    cin >> q;
    while(q--){
        long long ans = 0;
        cin >> l >> r;
        if(r&1){
            ans += (r>>1) - r;
        }else{
            ans += (r>>1);
        }
        l--;
        if(l&1){
            ans -= (l>>1) - l;
        }else{
            ans -= (l>>1);
        }
        cout << ans << '\n';
    }
    return 0;
}