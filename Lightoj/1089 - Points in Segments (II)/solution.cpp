#include <bits/stdc++.h>
using namespace std;
const int tam = 1e8+5;
struct node {
    int value, lazy;
    node *left, *right;
    node(){ 
        left = NULL;
        right = NULL;
        value = 0;
        lazy = 0;
    }
};
typedef node* parent;

void pushDown(parent &p) {
    if(p->lazy != 0) {
        p->value += p->lazy;
        if(p->left)
            p->left->lazy += p->lazy;
        if(p->right)
            p->right->lazy += p->lazy;
        p->lazy = 0;
    }
}

void del(parent &p) {
    if(p->left)
        del(p->left);
    if(p->right)
        del(p->right);
    delete p;
}

void update(parent &p, int L, int R, int l, int r) {
    if(!p) return;
    pushDown(p);
    if(R < l || r < L) return;
    if(l <= L && R <= r) { 
        p->lazy++;
        pushDown(p);
    } else {
        int mid = (L+R)>>1;
        update(p->left, L, mid, l, r);
        update(p->right, mid+1, R, l, r);
    }
}


int query(parent &p, int L, int R, int pos) {
    if(!p) p = new node();
    pushDown(p);
    if(R < pos || pos < L) return 0;
    if(L == R) { 
        return p->value;
    } else {
        int mid = (L+R)>>1;
        return query(p->left, L, mid, pos) + query(p->right, mid+1, R, pos);
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q;
    cin >> t;
    for(int r=1; r <= t; r++) {
        cin >> n >> q;
        cout << "Case " << r << ":\n";
        pair<int, int> segment[n];
        parent root = new node();
        for(int i=0; i < n; i++) {
            cin >> segment[i].first >> segment[i].second;
        }
        int v[q];
        for(int i=0; i < q; i++) {
            cin >> v[i];
            query(root, 0, tam, v[i]);
        }
        for(auto &i: segment) {
            update(root, 0, tam, i.first, i.second);
        }
        for(int i=0; i < q; i++) {
            cout << query(root, 0, tam, v[i]) << '\n';
        }
        del(root);
    }
    return 0;
}