#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;

class SegmentTree{
    private:
        int n;
        vi st;
        vii A;
        int left(int i){ return i<<1; }
        int right(int i){ return (i<<1) + 1; }
        void build(int p, int L, int R){
            if(L == R){
                st[p] = A[L].second - A[R].first + 1;
            }else{
                int p1 = left(p), p2 = right(p), mid = (L+R)>>1;
                build(p1, L, mid);
                build(p2, mid + 1, R);
                st[p] = max(st[p1], st[p2]);
            }
        }
        int rmq(int p, int L, int R, int l, int r){
            if(r < A[L].first || A[R].second < l)
                return -1;
            if(l <= A[L].first && A[R].second <= r)
                return st[p];
            if(L == R){
                if(A[L].first < l && r < A[L].second)
                    return r - l + 1;
                if(A[L].first < l)
                    return  A[L].second - l + 1;
                if(r < A[R].second)
                    return r - A[R].first + 1;
            }
            int mid = (L + R)>>1;
            int a = rmq(left(p), L, mid, l, r);
            int b = rmq(right(p), mid + 1, R, l, r);
            return max(a, b);
        }
        public:
            SegmentTree(vii _A){
                A = _A;
                n = A.size();
                st.assign(4*n, -1);
                build(1, 0, n-1);
            }
            int rmq(int l, int r){
                return rmq(1, 0, n-1, l, r);
            }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, temp, aux, a, b;
    while(cin >> n, n){
        cin  >> q;
        vector< pair<int, int> > v;
        cin >> temp;
        v.emplace_back( make_pair(0, 0) );
        for(int i=1; i<n; i++){
            cin >> aux;
            if(aux != temp){
                v[v.size() - 1.].second = i-1;
                v.emplace_back( make_pair(i, 0) );
                temp = aux;
            }
        }
        v[v.size() - 1].second = n-1;
        SegmentTree st(v);
        for(int i=0; i < q; i++){
            cin >> a >> b;
            cout << st.rmq(a-1, b-1) << '\n';
        }
    }
    return 0;
}