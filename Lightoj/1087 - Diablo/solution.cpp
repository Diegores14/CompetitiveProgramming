#include <bits/stdc++.h>
using namespace std;
const int tam = 200005;
int st[4*tam], v[tam];

void build(int p, int L, int R) {
    if( L == R ) {
        st[p] = 1;
    } else {
        int mid = (L + R) >> 1, left = (p<<1);
        build(left, L , mid);
        build(left+1, mid+1, R);
        st[p] = st[left] + st[left+1];
    }
}

void update(int p, int L, int R, int i) {
    if(R < i || i < L) return;
    if( L == R ) {
        st[p] = 0;
    } else {
        int mid = (L + R) >> 1, left = (p<<1);
        update(left, L , mid, i);
        update(left+1, mid+1, R, i);
        st[p] = st[left] + st[left+1];
    }
}

int query(int p, int L, int R, int pos) {
    if(L == R) return R;
    int mid = (L + R) >> 1, left = (p<<1);
    if(st[left] >= pos)
        return query(left, L , mid, pos);
    else 
        return query(left+1, mid+1, R, pos - st[left]);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q, x;
    char c;
    scanf("%d", &t);
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ":\n";
        scanf("%d %d", &n, &q);
        build(1, 0, tam-1);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        while(q--) {
            scanf("\n%c %d", &c, &x);
            if(c == 'a') {
                v[n++] = x;
            } else {
                int temp = query(1, 0, tam-1, x);
                if( temp < n) {
                    printf("%d\n", v[temp]);
                    update(1, 0, tam-1, temp);
                } else {
                    printf("none\n");
                }
            }
        }
    } 
    return 0;
}