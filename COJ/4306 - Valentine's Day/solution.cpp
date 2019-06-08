#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b, len[3];
    cin >> t; 
    while(t--) {
        cin >> a >> b >> len[0] >> len[1] >> len[2];
        int v[3] = {0, 1, 2};
        bool ans = false;
        do {
            int temp1 = 2*len[v[2]]+len[v[1]];
            int temp2 = 2*(len[v[0]]+len[v[2]]);
            int temp3 = len[v[2]]+len[v[1]];
            int temp4 = 3*len[v[0]]+len[v[2]]+len[v[1]];
            if((temp1 <= a && temp2 <= b) || (temp1 <= b && temp2 <= a) || 
                (temp3 <= a && temp4 <= b) || (temp3 <= b && temp4 <= a)) {
                    ans = true;
                    continue;
                }
        } while( next_permutation(v, v+3) );
        cout << (ans? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }
    return 0;
}