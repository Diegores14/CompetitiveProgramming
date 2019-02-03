#include<bits/stdc++.h>
using namespace std;
long long A, B, n, k;

struct node {
    long long value;
    int cant;
    node *left, *right;
    node() {value = 10000000000000000; cant = 0; left = nullptr; right = nullptr;}
};

node* update(node* p, int L, int R, int pos) {
    if(!p)
        p = new node();
    if(pos < L || R < pos) {
        if(p->cant == 0) {
            p->value = A;
        }
        return p;
    }
    if(L == R) {
        p->cant++;
        p->value = p->cant * B;
        return p;
    }
    int mid = (L+R)>>1;
    p->left = update(p->left, L, mid, pos);
    p->right = update(p->right, mid+1, R, pos);
    p->cant = p->left->cant + p->right->cant;
    p->value = min(p->cant * B * (R-L+1), p->left->value + p->right->value);
    return p;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> A >> B;
    int pos;
    node* root = nullptr;
    for(int i=0; i<k; i++) {
        cin >> pos;
        root = update(root, 1, (1<<n), pos);
    }
    cout << root->value << '\n';
    return 0;
}