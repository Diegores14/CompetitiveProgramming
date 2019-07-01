#include <bits/stdc++.h>
using namespace std;
const int tam = 30005;
const int tam1 = 4*30005;
int value[tam];
vector< list< int > > G;
int in[tam], out[tam], st[4*tam1], st1[4*tam1], id[tam], id1[tam];
bool used[tam];
int pos, pos1;

void update(int p, int b, int e, int l, int val) {
    //cout << "Hello" << b << ' ' << e << ' ' << l << "\n" ;
    if(l < b || e < l) return;
    if(b == e)  st[p] = val;
    else {
        int mid = (b+e)>>1, left = (p<<1), right = left + 1;
        update(left, b, mid, l, val);
        update(right, mid+1, e, l, val);
        st[p] = st[left] + st[right];
    }
}

int query(int p, int b, int e, int l, int r) {
    if(r < b || e < l) return 0;
    if(l <= b && e <= r)  return st[p];
    else {
        int mid = (b+e)>>1, left = (p<<1), right = left + 1;
        return query(left, b, mid, l, r) + query(right, mid+1, e, l, r);
    }
}

void update1(int p, int b, int e, int l, int val) {
    if(l < b || e < l) return;
    if(b == e)  st1[p] = val;
    else {
        int mid = (b+e)>>1, left = (p<<1), right = left + 1;
        update1(left, b, mid, l, val);
        update1(right, mid+1, e, l, val);
        st1[p] = min(st1[left], st1[right]);
    }
}

int query1(int p, int b, int e, int l, int r) {
    if(r < b || e < l) return 1e9;
    if(l <= b && e <= r)  return st1[p];
    else {
        int mid = (b+e)>>1, left = (p<<1), right = left + 1;
        return min( query1(left, b, mid, l, r), query1(right, mid+1, e, l, r) );
    }
}

void eulerTour(int idx) {
    used[idx] = true;
    in[idx] = pos++;
    id[idx] = pos1;
    id1[pos1++] = idx;
    update1(1, 0, tam1, in[idx], id[idx]);
    update(1, 0, tam1, in[idx], value[idx]);
    for(int &i : G[idx]) {
        if(!used[i]) {
            eulerTour(i);
            update1(1, 0, tam1, pos++, id[idx]);
        }
    }
    out[idx] = pos++;
    update1(1, 0, tam1, out[idx], id[idx]);
    update(1, 0, tam1, out[idx], -value[idx]);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q, u, v, c;
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++ ) {
        pos = pos1 = 0;
        memset(st, 0, sizeof st);
        for(int i = 0; i < 4*tam1; i++) {
            st1[i] = 1e9;
        }
        G.clear();
        scanf("%d", &n);
        memset(used, 0, sizeof used);
        G.assign(n, list<int>() );
        for( int i = 0; i < n; i++ ) {
            scanf("%d", &value[i]);
        }
        for( int i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d", &q);
        eulerTour(0);
        printf("Case %d:\n", cases);
        /* for(int i = 0; i < pos; i++) {
            printf("%d\n", query(1, 0, tam1, i, i) );
        }*/
        while(q--) {
            scanf("%d %d %d", &c, &u, &v);
            if(c) {
                update(1, 0, tam1, in[u], v);
                update(1, 0, tam1, out[u], -v);
                value[u] = v;
            } else {
                if(in[u] > in[v]) swap(u, v);
                int index = id1[query1(1, 0, tam1, in[u], in[v])];
                //printf("case: %d\n", in[v]);
                printf("%d\n", query(1, 0, tam1, in[index], in[u]) +
                                query(1, 0, tam1, in[index], in[v]) -
                                value[index]);
            }
        }
    }
    return 0;
}