#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+5;
int st1[4*tam], st2[4*tam];
int v[tam];

void update1(int p, int L, int R, int pos) {
    if(R < pos || pos < L) return;
    if(L == R) {
        st1[p] = v[L];
    } else {
        int mid = (L + R) >> 1, left = p<<1;
        update1(left, L, mid, pos);
        update1(left+1, mid+1, R, pos);
        st1[p] = max(st1[left], st1[left+1]);
    }
}

void update2(int p, int L, int R, int pos) {
    if(R < pos || pos < L) return;
    if(L == R) {
        st2[p] = v[L];
    } else {
        int mid = (L + R) >> 1, left = p<<1;
        update2(left, L, mid, pos);
        update2(left+1, mid+1, R, pos);
        st2[p] = min(st2[left], st2[left+1]);
    }
}

int query1(int p, int L, int R, int l, int r) {
    if(R < l || r < L) return 0;
    if(l <= L && R <= r) return st1[p];
    int mid = (L + R) >> 1, left = p<<1;
    int a1 = query1(left, L, mid, l, r);
    int a2 = query1(left+1, mid+1, R, l, r);
    return max(a1, a2);
}

int query2(int p, int L, int R, int l, int r) {
    if(R < l || r < L) return 1e9;
    if(l <= L && R <= r) return st2[p];
    int mid = (L + R) >> 1, left = p<<1;
    int a1 = query2(left, L, mid, l, r);
    int a2 = query2(left+1, mid+1, R, l, r);
    return min(a1, a2);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, d, temp;
    scanf("%d", &t);
    for(int k=1; k <= t; k++) {
        scanf("%d %d", &n, &d);
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            update1(1, 0, tam, i);
            update2(1, 0, tam, i);
            ans = max(ans, query1(1, 0, tam, i-d+1, i) - query2(1, 0, tam, i-d+1, i));
        }
        printf("Case %d: %d\n", k, ans);
    }
    return 0;
}