#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+5;
int st[4*tam], lazy[4*tam];
set<int> se;

void pushDown(int p, int b, int e) {
    if(b != e) {
        lazy[(p<<1)] = lazy[p];
        lazy[(p<<1)+1] = lazy[p];
    }
    st[p] = lazy[p];
    lazy[p] = 0;
}

void update(int p, int b, int e, int l, int r, int val) {
    if(r < b || e < l) return;
    if(lazy[p] != 0) pushDown(p, b, e);
    if(l <= b && e <= r) {
        if(b != e) {
            lazy[(p<<1)] = val;
            lazy[(p<<1)+1] = val;
        }
        st[p] = val;
    } else {
        int mid = (b+e)>>1;
        update(p<<1, b, mid, l, r, val);
        update((p<<1)+1, mid+1, e, l, r, val);
    }
}

void solve(int p, int b, int e) {
    if(lazy[p]) pushDown(p, b, e);
    if(b == e) {
        se.insert(st[p]);
    } else {
        int mid = (b+e)>>1;
        solve(p<<1, b, mid);
        solve((p<<1)+1, mid+1, e);
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL)
    int t, n, l, r; 
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++) {
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
        scanf("%d", &n);
        se.clear();
        int val = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &l, &r);
            update(1, 0, (n<<1), l, r, val++);
        }
        solve(1, 0, (n<<1));
        int ans = (int)se.size() - 1;
        printf("Case %d: %d\n", cases, ans);
    }
    return 0;
}