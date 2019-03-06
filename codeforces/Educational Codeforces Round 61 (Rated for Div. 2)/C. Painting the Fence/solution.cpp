#include <bits/stdc++.h>
using namespace std;
int desc[5005],  desc1[5005][5005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(desc, 0, sizeof desc);
    memset(desc1, 0, sizeof desc1);
    int v[5005][4];
    memset( v, 0, sizeof v);
    int n, q, a, b;
    long long total = 0;
    cin >> n >> q;
    for(int i=0; i<q; i++) {
        cin >> a >> b;
        for(int j=a; j<=b; j++) {
            if(v[j][3] < 3) {
                v[j][v[j][3]] = i;
                v[j][3]++;
                total += (v[j][3] == 1);
            }
        }
    }
    for(int i=0; i<=5000; i++) {
        if(v[i][3] == 1) {
            desc[v[i][0]]++;
        }
        if(v[i][3] == 2) {
            desc1[v[i][0]][v[i][1]]++;
        }
    }
    long long ans = 0;
    for(int i=0; i<q; i++) {
        for(int j=i+1; j<q; j++) {
            ans = max(ans, total - desc[i] - desc[j] - desc1[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}