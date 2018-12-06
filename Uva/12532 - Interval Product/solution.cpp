#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
    vi st;
    int n;
    int left(int p){ return (p<<1); }
    int right(int p){ return (p<<1) + 1; }
    void build(int p, int L, int R, const vi &A){
        if(L == R)
            st[p] = A[L]? abs(A[L])/A[L] : 0;
        else{
            int p1 = left(p), p2 = right(p);
            int mid = (L + R)>>1;
            build(p1, L, mid, A);
            build(p2, mid + 1, R, A);
            st[p] = st[p1] * st[p2];
        }
    }
    void update(int p, int L, int R, const int & i, const int & value){
        if(i < L || R < i)
            return;
        if(L == R)
            st[p] = value? abs(value)/value : 0;
        else{
            int p1 = left(p), p2 = right(p);
            int mid = (L + R)>>1;
            update(p1, L, mid, i, value);
            update(p2, mid + 1, R, i, value);
            st[p] = st[p1] * st[p2];
        }
    }
    int search(int p, int L, int R, int l, int r){
        if(r < L || R < l)
            return 1;
        if(l <= L && R <= r)
            return st[p];
        int mid = (L+R)>>1;
        int a = search(left(p), L, mid, l, r);
        int b = search(right(p), mid + 1, R, l, r);
        return a*b;
    }
    public:
    SegmentTree(vi & A){
        n = A.size();
        st.assign(n<<2, 1);
        build(1, 0, n-1, A);
    }
    void update(int i, int value){
        update(1, 0, n-1, i, value);
    }
    int search(int l, int r){
        return search(1, 0, n-1, l, r);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char c;
    int n, k, a, b;
    while(cin >> n >> k){
        vi v(n);
        for(int &i: v){
            cin >> i;
        }
        SegmentTree st(v);
        for(int i=0; i<k; i++){
            cin >> c >> a >> b;
            if(c == 'C'){
                st.update(a-1, b);
            }else{
                int ans = st.search(a-1, b-1);
                if(ans > 0){
                    cout << '+';
                }
                if(ans < 0){
                    cout << '-';
                }
                if(ans == 0){
                    cout << '0';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}