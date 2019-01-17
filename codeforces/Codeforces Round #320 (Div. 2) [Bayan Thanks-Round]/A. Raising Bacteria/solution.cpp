#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x;
    int ans = 0;
    cin >> x;
    while(x) {
        ans += x&1;
        x >>= 1;
    }
    cout << ans << '\n';
    return 0;
}