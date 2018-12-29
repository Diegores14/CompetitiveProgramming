#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, l, r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << l << ' ' << (l<<1) << '\n';
    }
    return 0;
}