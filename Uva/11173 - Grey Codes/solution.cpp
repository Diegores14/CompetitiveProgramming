#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << (b^(b>>1)) << '\n';
    }
    return 0;
}