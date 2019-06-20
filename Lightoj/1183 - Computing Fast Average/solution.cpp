#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5 + 1;
long long st[4 * tam], lazy[4 * tam];

long long GCD(long long a, long long b) {
    return b? GCD(b, a%b): a;
}

void pushDown(int node, int b, int e) {
    if(b != e) {
        lazy[2*node] = lazy[node];
        lazy[2*node + 1] = lazy[node];
    }
    st[node] = lazy[node] * (e - b + 1);
    lazy[node] = -1;
}

void update(int node, int b, int e, int l, int r, int v) {
    if(lazy[node] != -1) pushDown(node, b, e);
    if(r < b || e < l) return;
    if(l <= b && e <= r) {
        if(b != e) {
            lazy[2 * node] = v;
            lazy[2 * node + 1] = v;
        }
        st[node] = v * ( e - b + 1);
    } else {
        int mid = (b + e)>>1, left = 2*node, right = left + 1;
        update(left, b, mid, l, r, v);
        update(right, mid+1, e, l, r, v);
        st[node] = st[left] + st[right];
    }
}

long long query(int node, int b, int e, int l, int r) {
    if(lazy[node] != -1) pushDown(node, b, e);
    if(r < b || e < l) return 0;
    if(l <= b && e <= r) {
        return st[node];
    } else {
        int mid = (b + e)>>1, left = 2*node, right = left + 1;
        return query(left, b, mid, l, r) + query(right, mid+1, e, l, r);
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q, c, x, y, v;
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++) {
        printf("Case %d:\n", cases);
        memset(lazy, -1, sizeof lazy);
        memset(st, 0, sizeof st);
        scanf("%d %d", &n, &q);
        n--;
        while(q--) {
            scanf("%d %d %d", &c, &x, &y);
            if(c == 1) {
                scanf("%d", &v);
                update(1, 0, n, x, y, v);
            } else {
                long long ans = query(1, 0, n, x, y);
                long long den = y - x +1;
                long long d = GCD(ans, den);
                if(d == den) {
                    printf("%lld\n", ans/den);
                } else {
                    printf("%lld/%lld\n", ans/d, den/d);
                }
            }
        }
    }
    return 0;
}