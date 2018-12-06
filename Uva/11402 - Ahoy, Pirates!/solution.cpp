#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
    vi st, lazy;
    string  A;
    int n;
    int left(int p){ return p<<1; }
    int right(int p){ return (p<<1) + 1; }
    void build(int p, int L, int R){
        if(L == R){
            st[p] = A[L] - '0';
        }else{
            int p1 = left(p), p2 = right(p), mid = (L+R)>>1;
            build(p1, L, mid);
            build(p2, mid + 1, R);
            st[p] = st[p1] + st[p2];
        }
    }
    void push_down(int p, char option){
        if(option == 'F' || option == 'E')
            lazy[p] = option;
        if(option == 'I'){
            if(lazy[p] == 'F'){
                lazy[p] = 'E';
                return;
            }
            if(lazy[p] == 'E'){
                lazy[p] = 'F';
                return;
            }
            if(lazy[p] == 'I'){
                lazy[p] = 0;
                return;
            }
            if(lazy[p] == 0){
                lazy[p] = 'I';
            }
        }
    }
    void propagate(int p, int L, int R){
        if(lazy[p] != 0){
            if(lazy[p] == 'F'){
                st[p] = R-L + 1;
            }
            if(lazy[p] == 'E'){
                st[p] = 0;
            }
            if(lazy[p] == 'I'){
                st[p] = R-L + 1 - st[p];
            }
            if(L != R){
                push_down(left(p), lazy[p]);
                push_down(right(p), lazy[p]);
            }
            lazy[p] = 0;
        }
    }
    void update(int p, int L, int R, const int &l, const int &r, char option){
        propagate(p, L, R);
        if(r < L || R < l)
            return;
        if(l <= L && R <= r){
            lazy[p] = option;
            propagate(p, L, R);
        }else{
            int mid = (L+R)>>1;
            update(left(p), L, mid, l, r, option);
            update(right(p), mid + 1, R, l, r, option);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    int rmq(int p, int L, int R, int l, int r){
        propagate(p, L, R);
        if(r < L || R < l)
            return 0;
        if(l <= L && R <= r)
            return st[p];
        int mid = (L+R)>>1;
        int a = rmq(left(p), L, mid, l, r);
        int b = rmq(right(p), mid + 1, R, l, r);
        return a + b;
    }
    public:
        SegmentTree(string & _A){
            A = _A;
            n = A.size();
            st.assign(n<<2, 0);
            lazy.assign(n<<2, 0);
            build(1, 0, n-1);
        }
        void update(int l, int r, char option){
            update(1, 0, n-1, l, r, option);
        }
        int rmq(int l, int r){
            return rmq(1, 0, n-1, l, r);
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, m, q, n, a, b;
    char c;
    string s;
    cin >> t;
    for(int k =1; k<=t; k++){
        cout << "Case " << k << ":\n";
        string land;
        cin >> m;
        while(m--){
            cin >> n;
            cin >> s;
            for(int i=0; i<n; i++)
                land += s;
        }
        SegmentTree st(land);
        cin >> q;
        int i = 1;
        while(q--){
            cin >> c >> a >> b;
            if(c != 'S'){
                st.update(a, b, c);
            }
            else    
                cout << "Q" << i++ << ": " << st.rmq(a, b) << '\n';
        }
    }
    return 0;
}