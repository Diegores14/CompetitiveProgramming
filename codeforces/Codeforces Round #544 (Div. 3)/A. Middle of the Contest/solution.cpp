#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m1, m2, h1, h2;
    char c;
    cin >> h1 >> c >> m1;
    cin >> h2 >> c >> m2;
    int ans = (h1*60 + m1) + (h2*60 + m2);
    ans /= 2;
    if(ans/60 <10){
        cout << 0 << ans/60;
    } else {
        cout << (ans/60);
    }
    cout << ":" ;
    if(ans%60 < 10) {
        cout << 0 << ans%60 << '\n';
    } else {
        cout << ans%60 << '\n';
    }
    return 0;
}