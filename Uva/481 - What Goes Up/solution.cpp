#include <bits/stdc++.h>
using namespace std;

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
    vector<long long > v;
    long long  temp, L = 100000000000000, R = -100000000000000;
    while(cin >> temp){
        v.emplace_back(temp);
        L = min(L, temp);
        R = max(R, temp);
    }
    node* root = nullptr;
    vector<int> dp(v.size(), 0);
    for(int i=0; i < v.size(); i++){
        dp[i] = rmq(root, L, R, L, v[i]-1) + 1;
        update(root, L, R, v[i], dp[i]);
    }
    int mmax = rmq(root, L, R, L, R);
    cout << mmax << "\n-\n";
    vector<long long> ans(mmax);
    for(int i = v.size() - 1; i >= 0; i--){
        if(dp[i] == mmax){
            ans[mmax - 1] = v[i];
            mmax--;
        }
    }
    for(int i: ans){
        cout << i << '\n';
    }
    return 0;
}