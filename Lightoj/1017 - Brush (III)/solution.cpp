#include <bits/stdc++.h>
using namespace std;
const int tam = 105;
int dp[tam][tam];
pair<int, int> v[tam];
int t, n, w, k;

int search(int idx) {
    int l = idx, r = n;
    while(r-l != 1) {
        int mid = (l+r)>>1;
        if(v[idx].first + w < v[mid].first) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int solve(int idx, int cant) {
    if(idx >= n || cant == 0) return 0;
    int &ans = dp[idx][cant];
    if(ans != -1) return ans;
    int temp = search(idx);
    ans = max(temp - idx + solve(temp, cant-1), solve(idx + 1, cant));
    return ans;
}

int main() {
    //ios_base::stync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cout << "Case " << r << ": ";
        cin >> n >> w >> k;
        for(int i=0; i<n; i++) {
            cin >> v[i].second >> v[i].first;
        }
        sort(v, v + n);
        memset(dp, -1, sizeof dp);
        cout << solve(0, k) << '\n';
    }
    return 0;
}