#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, aux;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0, left = 0;
        map<int, int> m;
        for(int i=1; i<=n; i++){
            cin >> aux;
            left = max(m[aux], left);
            m[aux] = i;
            ans = max(ans, i - left);
        }
        cout << ans << '\n';
    }
    return 0;
}