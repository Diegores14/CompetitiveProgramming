#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    bool invert;
    node *left, *right;
    node() {
        invert = false;
        value = 0;
        left = nullptr;
        right = nullptr;
    }
};

void push(node* &p, int L, int R) {
    if(p->invert) {
        p->value = R - L + 1 - p->value; 
    }
    if(!p->left) {
        p->left = new node();
    }
    p->left->invert ^= p->invert;
    if(!p->right) {
        p->right = new node();
    }
    p->right->invert ^= p->invert;
    p->invert = false;
}

void update(node* &p, int L, int R, int l, int r) {
    if(!p) {
        p = new node();
    }
    push(p, L, R);
    if(r < L || R < l) {
        return;
    }
    if(l <= L && R <= r) {
        p->invert = true;
        push(p, L, R);
        return;
    }
    int mid = (L+R)>>1;
    update(p->left, L, mid, l, r);
    update(p->right, mid+1, R, l, r);
    p->value = p->left->value + p->right->value;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x1, y1, x2, y2;
    cin >> n;
    vector< pair<int , pair<int, int> > >v(n*2);
    for(int i=0; i<n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 > y2) {
            swap(y1, y2);
        }
        v[i*2] = make_pair(x1, make_pair(y1, y2));
        v[i*2 + 1] = make_pair(x2, make_pair(y1, y2));
    }
    sort(v.begin(), v.end());
    node* root = new node();
    int x = 0;
    long long ans = 0;
    for(auto &i : v) {
        ans += (long long)(i.first - x) * root->value;
        update(root, 0, 1000000001, i.second.first, i.second.second - 1);
        x = i.first;
    }
    cout << ans << '\n';
    return 0;
}