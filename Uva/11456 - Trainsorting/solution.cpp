#include <bits/stdc++.h>
using namespace std;
long long TAM = 1e15;

struct node{
    int value;
    node *left, *right;
    node(){
        value = 0;
        left = nullptr;
        right = nullptr;
    }
};

void update(node* & p, long long l, long long r, long long &i, int &value){
    if(p == nullptr)
        p = new node();
    if(i < l || r < i)
        return;
    if(l == r){
        p->value = value;
    }else{
        int mid = (l+r)>>1;
        update(p->left, l, mid, i, value);
        update(p->right, mid+1, r, i, value);
        p->value = max(p->left->value, p->right->value);
    }
}

int rmq(node* &p, long long L, long long R, long long l, long long r){
    if(p == nullptr)
        p =  new node();
    if(r < L || R < l)
        return 0;
    if(l <= L && R <= r)
        return p->value;
    int mid = (L+R)>>1;
    return max(rmq(p->left, L, mid, l, r), rmq(p->right, mid+1, R, l, r));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<long long> v(n);
        int dp[2][n];
        int ans = 0;
        node *root1=nullptr, *root2=nullptr;
        for(long long &i: v)
            cin >> i;
        for(int i=n-1; i>=0; i--){
            dp[0][i] = rmq(root1, 0, TAM, 0, v[i] - 1) + 1;
            dp[1][i] = rmq(root2, 0, TAM, v[i] + 1, TAM) + 1;
            update(root1, 0, TAM, v[i], dp[0][i]);
            update(root2, 0, TAM, v[i], dp[1][i]);
            ans = max(ans, dp[0][i] + dp[1][i] - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}