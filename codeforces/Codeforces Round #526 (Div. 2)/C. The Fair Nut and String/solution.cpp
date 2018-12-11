#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;

struct node{
    int value;
    *node left, right;
    node(){value 0; left = nullptr; right = nullptr;}
};

void update(node* p, int L, int R, int i, int value){
    if(i < L || R < i)
        return;
    if(L == R){
        p->value = value;
    }else{
        int mid = (L+R)>>1;
        update(p->left, L, mid, i, value);
        update(p->right, mid + 1, R, i, value);
    }
}

long long rmq(node* p, int L, int R, int l, int r){
    if(r < L || R < l)
        return 0;
    if(l <= L && R <= r){
        return p->value;
    }else{
        int mid = (L+R)>>1;
        long long a = rmq(p->left, L, mid, i, value);
        long long b = (p->right, mid + 1, R, i, value);
        return (a + b)%M;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long ans = 0, resAnt = 0, pos;
    string s;
    cin >> s;
    vector<int> preffixa(s.size()+1, 0);
    vector<int> preffixb(s.size()+1, 0);
    for(int i=0; i<s.size(); i++){
        preffixa[i+1] = preffixa[i];
        preffixb[i+1] = preffixb[i];
        if(s[i]=='a'){
            preffixa[i+1]++;
            ans++;
        }
        if(s[i] == 'b'){
            preffixb[i+1]++;
        }
    }
    pos = s.size();
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == 'a'){
            if(preffixb[pos]-preffixb[i+1] > 0){
                pos = i+1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}