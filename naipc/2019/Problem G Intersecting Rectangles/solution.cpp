#include <bits/stdc++.h>
using namespace std;
const int tam = 1e9 + 5;

struct node {
    int val;
    node *left, *right;
    node() {
        val = 0;
        left = nullptr; 
        right = nullptr;
    }
};

struct point {
    int val, x, y1, y2;
    bool operator <(point other) const {
        return x < other.x;
    }
};

void update(node* &p, int L, int R, int pos, const int val) {
    if(p == nullptr) {
        p = new node();
    }
    if(pos < L || R < pos) {
        return;
    }
    if(L == R ) {
        p->val = val;
        return;
    }
    int mid = (L+R) >> 1;
    update(p->left, L, mid, pos, val);
    update(p->right, mid+1, R, pos, val);
    p->val = p->left->val + p->right->val;
}

int rsq(node* &p, int L, int R, int l, int r) {
    if(p == nullptr) {
        p = new node();
    }
    if(r < L || R < l) {
        return 0;
    }
    if(l <= L && R <= r) {
        return p->val;
    }
    int mid = (L+R)>>1;
    return rsq(p->left, L, mid, l, r) + rsq( p->right, mid+1, R, l, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x1, x2, y1, y2;
    cin >> n;
    vector<point> v(n*2);
    for(int i=0; i<n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int j = i<<1;
        v[j].y1 = y1;
        v[j].y2 = y2;
        v[j].x = x1;
        v[j].val = 1;
        v[j+1].y1 = y1;
        v[j+1].y2 = y2;
        v[j+1].x = x2;
        v[j+1].val = 0;
    }
    sort(v.begin(), v.end());
    node* root = nullptr;
    for(auto &i: v) {
        if(rsq(root, -tam, tam, i.y1+1, i.y2-1) > 0) {
            cout << 1 << '\n';
            return 0;
        }
        update(root, -tam, tam, i.y1, i.val);
        update(root, -tam, tam, i.y2, i.val);
    }
    cout << 0 << '\n';
    return 0;
}