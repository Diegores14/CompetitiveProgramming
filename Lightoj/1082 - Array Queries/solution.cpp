#include <bits/stdc++.h>
using namespace std;
const int tam = 100000;
int v[tam];

class segmentTree {
    public:
    int st[4*tam];
    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = v[L];
        } else {
            int mid = (L+R)>>1, left = p<<1;
            build(left, L, mid);
            build(left+1, mid+1, R);
            st[p] = min(st[left], st[left+1]);
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if(j < L || R < i) {
            return 1000000000;
        }
        if(i <= L && R <= j) {
            return st[p];
        } else {
            int mid = (L + R)>>1, left = p<<1;
            int x = rmq(left, L, mid, i, j);
            int y = rmq(left+1, mid+1, R, i, j);
            return min(x, y);
        }
    }
};

int main() {
    //ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t, n, q, a, b;
    segmentTree st;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ":\n";
        cin >> n >> q;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        st.build(1, 0, n-1);
        while(q--) {
            cin >> a >> b;
            //cout << a << ' ' << b << ' ' ;
            cout << st.rmq(1, 0, n-1, a-1, b-1) << '\n';
        }
    }
    return 0;
}