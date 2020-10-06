#include <bits/stdc++.h>
using namespace std;
int tam = 1e9+7;
 
struct node  {
    node *left, *right;
    int value;
    node(){ value = 0; left = nullptr; right = nullptr; }
};
 
void update( node* &p, int b, int e, int pos, int value ) {
    if( !p ) p = new node();
    if( pos < b || e < pos ) return;
    if(b == e) {
        p->value = value;
    } else {
        int mid = (b+e)/2;
        update( p->left, b, mid, pos, value);
        update( p->right, mid+1, e, pos, value);
        p->value = max(p->left->value, p->right->value);
    }
}
 
int query( node* &p, int b, int e, int l, int r ) {
    if( !p ) { p = new node(); }
    if( r < b || e < l ) return 0;
    if( l <= b && e <= r ) return p->value;
    else {
        int mid = (b+e)/2;
        return max( query( p->left, b, mid, l, r), query( p->right, mid+1, e, l, r) );
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    node *root = new node();
    for( int i = 0; i < n; i++ ) {
        int mmax = query(root, 0, tam, 0, a[i]-1);
        update(root, 0, tam, a[i], mmax+1);
    }
    cout << query(root, 0, tam, 0, tam) << '\n';
    return 0;
}
