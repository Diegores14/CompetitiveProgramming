#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int ans = 7-max(a,b);
    if(ans == 6) {
        cout << "1/1\n";
    } else {
        if(ans == 3) {
            cout << "1/2\n";
        } else {
            if( ans == 2 ) {
                cout << "1/3\n";
            } else {
                if ( ans == 4)
                    cout << "2/3\n";
                else
                    cout << ans << "/6\n";
            }
        }
    }
    return 0;
}