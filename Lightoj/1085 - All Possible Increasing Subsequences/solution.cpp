#include <bits/stdc++.h>
using namespace std;
const int tam = 100005;
int st[4*tam];
int mod = 1000000007;

void update(int p, int L, int R, int pos, int value) {
    if(R < pos || pos < L) return;
    if(L == R) { 
        st[p] = (st[p] + value) % mod;
    } else {
        int mid = ((L + R) >> 1), left = (p << 1);
        update(left, L, mid, pos, value);
        update(left + 1, mid+1, R, pos, value);
        st[p] = (st[left] + st[left+1]) % mod;
    }
}

int query(int p, int L, int R, int i, int j) {
    if( R < i || j < L) return 0;
    if(i <= L && R <= j) return st[p];
    int mid = (L+R)>>1, left = p<<1;
    int a1 = query(left, L, mid, i, j);
    int a2 = query(left+1, mid+1, R, i, j);
    return (a1 + a2) % mod;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n; 
    map< int, int > m;
    scanf("%d", &t);
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ": ";
        memset(st, 0, sizeof st);
        scanf("%d", &n);
        int v[n], aux[n];
        for(int i=0; i < n; i++) {
            scanf("%d", &v[i]);
            aux[i] = v[i];
        }
        sort(aux, aux+n);
        for(int &i : aux) {
            if(m.count(i) == 0) 
                m[i] = m.size();
        }
        for(int i = n-1; i >= 0; i--) {
            int temp = query(1, 0, tam-1, m[v[i]]+1, tam-1);
            update(1, 0, tam-1, m[v[i]], (temp+1)%mod);
        }
        cout << query(1, 0, tam-1,  0, tam-1) << '\n';
        m.clear();
    }
    return 0;
}