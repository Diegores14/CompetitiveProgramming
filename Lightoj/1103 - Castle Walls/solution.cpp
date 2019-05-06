#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+5;
int st[4*tam]; 

void update(int p, int L , int R, int pos) {
    if(R < pos || pos < L) return;
    if( L == R ) {
        st[p]++;
    } else {
        int mid = (L + R) >> 1, left = p<<1;
        update(left, L, mid, pos);
        update(left+1, mid+1, R, pos);
        st[p] = st[left] + st[left+1];
    }
}

int query(int p, int L, int R, int l, int r) {
    if(R < l || r < L)  return 0;
    if(l <= L && R <= r) {
        return st[p];
    } else {
        int mid = (L+R) >> 1, left = p<<1;
        int a1 = query(left, L, mid, l, r);
        int a2 = query(left+1, mid+1, R, l, r);
        return a1 + a2;
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cout << "Case " << r << ": ";
        long long ans = 0;
        memset(st, 0, sizeof st);
        cin >> n >> m;
        pair<int, int> v[n+m];
        for(auto &i: v) {
            cin >> i.first >> i.second;
        }
        sort(v, v+n+m);
        for(auto &i: v) {
            ans += query(1, 0, tam, i.second, tam);
            update(1, 0, tam, i.second);
        }
        cout << ans << '\n';
    }
    return 0;
}