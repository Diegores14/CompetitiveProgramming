#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n || m){
        if(n == 0 || m == 0){
            cout << "0" << " knights may be placed on a " << n << " row " << m << " column board.\n";
            continue;
        }
        if(n == 1 || m == 1){
            cout << max(n, m) << " knights may be placed on a " << n << " row " << m << " column board.\n";
            continue;
        }
        if(n == 2 || m == 2){
            int ans = (max(n,m)/4)*4;
            int res = max(n,m)%4;
            if(res<=2)
                ans += res*2;
            else
                ans += 4;
            cout << ans << " knights may be placed on a " << n << " row " << m << " column board.\n";
            continue;
        }
        cout << ((n>>1)+(n&1)) * ((m>>1)+(m&1)) + (n>>1)*(m>>1) << " knights may be placed on a " << n << " row " << m << " column board.\n";
    }
    return 0;
}