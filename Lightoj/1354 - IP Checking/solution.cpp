#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    int v[2][4];
    for(int cases = 1; cases <= t; cases++) {
        scanf("%d.%d.%d.%d", &v[0][0], &v[0][1], &v[0][2], &v[0][3]);
        scanf("%d.%d.%d.%d", &v[1][0], &v[1][1], &v[1][2], &v[1][3]);
        bool ans = true;
        for(int j = 0; j < 4; j++) {
            for(int i = 0; i < 8; i++) {
                if(((v[0][j]>>i)&1) != v[1][j]%10) {
                    ans = false; break;
                }
                v[1][j] /= 10;
            }
        }
        cout << "Case " << cases << ": " << (ans? "Yes" : "No") << '\n';
    }
    return 0;
}