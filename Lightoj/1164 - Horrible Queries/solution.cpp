#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+1;
long long st[4*tam], lazy[4*tam];

void pushDown(int node, int b, int e) {
    int left = (node << 1), right = left+1;
    if(b != e) {
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }
    st[node] += lazy[node]*(e-b+1);
    lazy[node] = 0;
}

void update(int node, int b, int e, int l, int r, int v) {
    if(lazy[node]) pushDown(node, b, e);
    if(r < b || e < l) return;
    if(l <= b && e <= r) {
        if(b != e) {
            lazy[(node<<1)] += v;
            lazy[(node<<1) + 1] += v;
        }
        st[node] += v*(e-b+1);
    } else {
        int mid = (b+e)>>1, left = (node<<1), right = left+1;
        update(left, b, mid, l, r, v);
        update(right, mid + 1, e, l, r, v);
        st[node] = st[2*node] + st[2*node + 1];
    }
}

long long query(int node, int b, int e, int l, int r) {
    if(lazy[node]) pushDown(node, b, e);
    if(r < b || e < l) return 0;
    if(l <= b && e <= r) return st[node];
    else {
        int mid = (b+e)>>1, left = (node<<1), right = left+1;
        return query(left, b, mid, l, r) + query(right, mid + 1, e, l, r);
    }
}

int main() {
    int t, c, x, y, v, n, q;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        printf("Case %d:\n", cases);
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
        scanf("%d %d", &n, &q);
        n--;
        for(int i = 0; i < q; i++) {
            scanf("%d %d %d", &c, &x, &y) ;
            if(c) {
                long long ans = query(1, 0, n, x, y);
                printf("%lld\n", ans);
            } else {
                scanf("%d", &v);
                update(1, 0, n, x, y, v);
            }
        }
    }
    return 0;
}