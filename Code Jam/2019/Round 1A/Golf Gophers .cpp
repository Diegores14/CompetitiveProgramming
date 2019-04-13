#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n, m, temp, ans = 0;
    cin >> t >> n >> m;
    for(int k=1; k <= t; k++) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<18; j++) {
                cout << 18 << (j==17? '\n' : ' ');
            }
            cout.flush();
            sum = 0;
            for(int j=0; j<18; j++) {
                cin >> temp;
                sum += temp;
            }
            ans = max(sum, ans);
        }
        cout << ans << '\n';
        cout.flush();
        int sol;
        cin >> sol;
        if(sol == -1) {
            return 0;
        }
    }
    return 0;
}