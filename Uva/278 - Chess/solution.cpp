#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    char c;
    cin >> t;
    while(t--){
        cin >> c >> n >> m;
        if(c == 'r'){
            cout << min(n, m) << '\n';
        }
        if(c == 'k'){
            cout << ((n>>1) + (n&1)) * ((m>>1) + (m&1)) + (n>>1) * (m>>1) << '\n';
        }
        if(c == 'Q'){
            cout << min(n, m) << '\n';
        }
        if(c == 'K'){
            cout << ((n>>1) + (n&1)) * ((m>>1) + (m&1)) << '\n';
        }
    }
    return 0;
}