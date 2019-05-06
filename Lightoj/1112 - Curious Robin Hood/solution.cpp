#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+5;
int v[tam], st[4*tam];

void build(int p, int L, int R) {
    if(L == R) {
        st[p] = v[L];
    } else {
        int mid = (L+R)>>1, left = p<<1;
        build(left, L, mid);
        build(left+1, mid+1, R);
        st[p] = st[left] + st[left+1];
    }
}

void update(int p, int L, int R, int pos) {
    if(R < pos || pos < L) return;
    if(L == R) {
        st[p] = v[L];
    } else {
        int mid = (L+R)>>1, left = p<<1;
        update(left, L, mid, pos);
        update(left+1, mid+1, R, pos);
        st[p] = st[left] + st[left+1];
    }
}

int query(int p, int L, int R, int l, int r) {
    if(R < l || r < L) return 0;
    if(l <= L && R <= r) {
        return st[p];
    } else {
        int mid = (L+R)>>1, left = p<<1;
        int a1 = query(left, L, mid, l, r);
        int a2 = query(left+1, mid+1, R, l , r);
        return a1 + a2;
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q, a, b, c;
    scanf("%d", &t);
    for(int r = 1; r <= t; r++) {
        printf("Case %d:\n", r);
        scanf("%d %d", &n, &q);
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        build(1, 0, n-1);
        while(q--) {
            scanf("%d %d", &a, &b);
            if(a == 1) {
                printf("%d\n", v[b]);
                v[b] = 0;
                update(1, 0, n-1, b);
            } else {
                scanf("%d", &c);
                if(a == 2) {
                    v[b] += c;
                    update(1, 0, n-1, b);
                } else {
                    printf("%d\n", query(1, 0, n-1, b, c));
                }
            }
        }
    }
    return 0;
}