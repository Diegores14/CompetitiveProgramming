#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+5;
int v[tam];
int indexLeft[tam], indexRight[tam], prefixsum[tam];
int st[4*tam];

void build(int node, int b, int e) {
    if(b == e) {
        st[node] = prefixsum[b];
    } else {
        int mid = (b+e)/2, left = 2*node, right = left + 1;
        build(left, b, mid);
        build(right, mid+1, e);
        st[node] = max(st[left], st[right]);
    }
}

int query(int node, int b, int e, int l, int r) {
    if(r < b || e < l) return 0;
    if(l <= b && e <= r) return st[node];
    int mid = (b+e)/2, left = 2*node, right = left + 1;
    int a1 = query(left, b, mid, l, r);
    int a2 = query(right, mid+1, e, l, r);
    return max(a1, a2);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, c, q, l, r;
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++) {
        scanf("%d %d %d", &n, &c, &q);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }
        l = 1;
        r = n;
        int acc = 0;
        v[0] = v[n+1] = 0;
        for(int i = 1; i <= n; i++) {
            if(v[i] != v[i-1]) {
                l = i;
                acc = 0;
            }
            if(v[n-i+1] != v[n-i+2]) {
                r = n-i+1;
            }
            indexLeft[i] = l;
            indexRight[n-i+1] = r;
            prefixsum[i] = ++acc;
        }
        //printf("Debug\n");
        /*for(int i = 0; i <= n; i++) {
            printf("%d %d %d\n", indexLeft[i], indexRight[i], prefixsum[i]);
        }*/
        build(1, 1, n);
        printf("Case %d:\n", cases);
        while(q--) {
            scanf("%d %d", &l, &r);
            int a1 = prefixsum[min(r,indexRight[l])];
            if(indexLeft[l] < l)
                a1 -= prefixsum[l-1];
            int a2 = prefixsum[r];
            if(indexLeft[r] < l) {
                a2 -= prefixsum[l-1];
            }
            //printf("%d %d\n", a1, a2);
            int ans = max(a1, a2);
            l = indexRight[l]+1;
            r = indexLeft[r]-1;
            if(l <= r) {
                ans = max(ans, query(1, 1, n, l, r));
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}