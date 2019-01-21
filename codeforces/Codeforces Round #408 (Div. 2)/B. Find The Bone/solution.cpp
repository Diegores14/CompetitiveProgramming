#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    vector<bool> hole(1000005, false);
    cin >> n >> m >> k;
    int temp;
    for(int i=0; i<m; i++) {
        cin >> temp;
        hole[temp] = true;
    }
    int x = 1, a, b;
    if(hole[x]) {
        cout << x << '\n';
        return 0;
    }
    for(int i=0; i<k; i++) {
        cin >> a >> b;
        if( a == x || b == x) {
            x = a+b-x;
            if(hole[x]) {
                cout << x << '\n';
                return 0;
            }
        }
    }
    cout << x << '\n';
    return 0;
}