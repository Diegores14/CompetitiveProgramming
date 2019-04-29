#include <bits/stdc++.h>
using namespace std;
const int tam = 4*100000 + 50;
int st[tam];
string s; 

void update(int p, int L, int R, int i, int j) {
    if(j < L || R < i) return;
    if(i <= L && R <= j) {
        st[p]++;
        return;
    }
    int mid = (L + R)>>1;
    update((p<<1), L, mid, i, j);
    update((p<<1)+1, mid+1, R, i, j);
}

void query(int p, int L, int R, int pos) {
    if(pos < L || R < pos) return;
    if(st[p] != 0) {
        if(L != R) {
            st[(p<<1)] += st[p];
            st[(p<<1)+1] += st[p];
            st[p] = 0;
        }
    }
    if(L == R) {
        if(st[p]&1) {
            if(s[L] == '1') {
                s[L] = '0';
            } else {
                s[L] = '1';
            }
        }
        st[p] = 0;
    } else {
        int mid = (L + R)>>1;
        query((p<<1), L, mid, pos);
        query((p<<1)+1, mid+1, R, pos);
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, q, a, b, n;
    char c;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ":\n";
        memset(st, 0, sizeof st);
        cin >> s;
        n = s.size();
        cin >> q;
        while(q--) {
            cin >> c;
            if(c == 'I') {
                cin >> a >> b;
                a--; b--;
                update(1, 0, n-1, a, b);
            } else if(c == 'Q') {
                cin >> a;
                a--;
                query(1, 0, n-1, a);
                cout << s[a] << '\n';
            }
        }
    }
    return 0;
}