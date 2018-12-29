#include <bits/stdc++.h>
using namespace std;

struct node{
    long long value;
    node *left, *right;
    node(){
        left = nullptr;
        right = nullptr;
        value = 0;
    }
};

void update(node* &p, int L, int R, int i, long long value){
    if(p == nullptr){
        p = new node();
    }
    if(i < L || R < i){
        return;
    }
    if(L == R){
        p->value = max(p->value, value);
    }else{
        int mid = (L + R)>>1;
        update(p->left, L, mid, i, value);
        update(p->right, mid + 1, R, i, value);
        p->value = max(p->left->value, p->right->value);
    }
}

long long rmq(node* &p, int L, int R, int i, int j){
    if(p == nullptr){
        p = new node();
    }
    if(j < L || R < i)
        return 0;
    if(i <= L && R <= j){
        return p->value;
    }
    int mid = (L + R)>>1;
    long long a = rmq(p->left, L, mid, i, j);
    long long b = rmq(p->right, mid + 1, R, i, j);
    return max(a, b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int k=1; k<=t; k++){
        cin >> n;
        cout << "Case " << k << ". ";
        int v[2][n];
        long long dp[2][n];
        for(int &i: v[0])
            cin >> i;
        for(int &i: v[1])
            cin >> i;
        node *root1 = nullptr, *root2 = nullptr;
        for(int i=0; i<n; i++){
            dp[0][i] = rmq(root1, 0, 1e9, 0, v[0][i]-1) + v[1][i];
            update(root1, 0, 1e9, v[0][i], dp[0][i]);
            dp[1][i] = rmq(root2, 0, 1e9, v[0][i]+1, 1e9) + v[1][i];
            update(root2, 0, 1e9, v[0][i], dp[1][i]);
        }
        long long increasing = rmq(root1, 0, 1e9, 0, 1e9);
        long long decreasing = rmq(root2, 0, 1e9, 0, 1e9);
        if(increasing >= decreasing){
            cout << "Increasing (" << increasing << "). Decreasing (" << decreasing << ").\n";
        }else{
            cout << "Decreasing (" << decreasing << "). Increasing (" << increasing << ").\n";
        }
    }
    return 0;
}