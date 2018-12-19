#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '.'){
                ans++;
                for(int j=0; j<3; j++){
                    s[i+j] = '#';
                }
            }
        }
        cout << "Case " << k << ": " << ans << '\n';
    }
    return 0;
}