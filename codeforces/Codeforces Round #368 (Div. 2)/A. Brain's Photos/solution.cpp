#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    bool ans = true;
    cin >> n >> m;
    char c;
    for(int j=0; j<n; j++)
    for(int i=0; i<m; i++) {
        cin >> c;
        if(c == 'C' || c == 'Y' || c == 'M') {
            ans = false;
        }
    }
    if(ans) {
        cout << "#Black&White\n";
    } else {
        cout << "#Color\n";
    }
    return 0;
}