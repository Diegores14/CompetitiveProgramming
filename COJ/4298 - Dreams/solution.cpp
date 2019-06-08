#include <bits/stdc++.h>
using namespace std;
const int tam = 1001;
bool dreams[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, temp;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(dreams, 0, sizeof dreams);
        for(int i = 0; i < m; i++) {
            cin >> temp;
            dreams[temp] = true;
        }
        int j = 0;
        for(int i=1; i <=n; i++) {
            if(!dreams[i]) {
                cout << ( j? " " : "") << i;
                j++;
            }
        }
        cout << '\n';
    }
    return 0;
}