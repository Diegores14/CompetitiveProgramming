#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e9+7;

int p[100005], ranking[100005];
bool used[100005];

int findSet(int j) { return p[j] == j? j : p[j] = findSet(p[j]); }

void unionFind(int i, int j) {
    if(findSet(i) != findSet(j)) {
        int x = findSet(i), y = findSet(j);
        p[x] = y;
        ranking[y] += ranking[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, u, v, x;
    cin >> n >> k;
    for(int i=0; i <= 100004; i++) {
        p[i] = i;
        ranking[i] = 1;
    }
    long long ans = 1;
    for(int i=0; i<k; i++) {
        ans = (ans * n) % mod;
    }
    for(int i=1; i<n; i++) {
        cin >> u >> v >> x;
        if(x == 0) {
            unionFind(u, v);
        }
    }
    memset(used, 0, sizeof used);
    for(int i=1; i <= n; i++) {
        int temp = findSet(i);
        if(!used[temp]) {
            used[temp] = true;
            long long sum = 1;
            for(int i=0; i<k; i++) {
                sum = (sum * ranking[temp]) % mod;
            }
            ans = (ans - sum) % mod;
        }
    }
    if(ans < 0) {
        ans += mod;
    }
    cout << ans << '\n';
    return 0;
}