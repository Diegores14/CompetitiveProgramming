#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5 + 5;
int st[3][4*tam], lazy[4*tam];


void pushDown(int node, int b, int e) {
    if(b != e) {
        lazy[2*node] = (lazy[2*node] + lazy[node])%3;
        lazy[2*node + 1] = (lazy[2*node + 1] + lazy[node])%3;
    }
    if(lazy[node] == 1) {
        st[2][node] = st[1][node];
        st[1][node] = st[0][node];
        st[0][node] = e - b + 1 - (st[1][node] + st[2][node]);
    }
    if(lazy[node] == 2) {
        st[1][node] = st[2][node];
        st[2][node] = st[0][node];
        st[0][node] = e - b + 1 - (st[1][node] + st[2][node]);
    }
    lazy[node] = 0;
}

void update(int node, int b, int e, int l, int r) {
    if(lazy[node]) pushDown(node, b, e);
    if(r < b || e < l) return;
    if(l <= b && e <= r) {
        if(b != e) {
            lazy[2*node] = (lazy[2*node] + 1)%3;
            lazy[2*node + 1] = (lazy[2*node + 1] + 1)%3;
        }
        st[2][node] = st[1][node];
        st[1][node] = st[0][node];
        st[0][node] = e - b + 1 - st[1][node] - st[2][node];
    } else {
        int mid = (b+e)>>1;
        update(2*node, b, mid, l, r);
        update(2*node + 1, mid + 1, e, l, r);
        st[0][node] = st[0][2*node] + st[0][2*node + 1];
        st[1][node] = st[1][2*node] + st[1][2*node + 1];
        st[2][node] = st[2][2*node] + st[2][2*node + 1];
    }
}

void init(int node, int b, int e) {
    st[1][node] = 0;
    st[2][node] = 0;
    lazy[node] = 0;
    if(b == e) {
        st[0][node] = 1;
    } else {
        int mid = (b + e) >> 1;
        init(2*node, b, mid);
        init(2*node + 1, mid+1, e);
        st[0][node] = st[0][2*node] + st[0][2*node + 1];
    }
}
 
int query(int node, int b, int e, int l, int r) {
    if(lazy[node]) pushDown(node, b, e);
    if(r < b || e < l) return 0;
    if(l <= b && e <= r) return st[0][node];
    int mid = (b+e)>>1;
    return query(2*node, b, mid, l, r) + query(2*node + 1, mid+1, e, l, r);
} 

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, t;
    int a, b, c;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cout << "Case " << cases << ":\n";
        cin >> n >> q;
        n--;
        init(1, 0, n);
        for(int i = 0; i < q; i++) {
            cin >> c >> a >> b;
            if(c) {
                cout << query(1, 0, n, a, b) << '\n';
            } else {
                update(1, 0, n, a, b);
            }
        }
    }
    return 0;
}
