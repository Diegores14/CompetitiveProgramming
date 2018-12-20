#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    unsigned long long n, l, u;
    while(cin >> n >> l >> u){
        unsigned long long ans = 0;
        for(int i=31; i>=0; i--){
            if(ans + (1LL << i) -1 < l){
                ans += (1LL << i);
            }else{
                if((ans + (1LL<<i)) <= u && (ans + (1LL<<i)) >= l){
                    if((n & (1LL<<i)) == 0){
                        ans += (1LL<<i);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}