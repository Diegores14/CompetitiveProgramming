#include <bits/stdc++.h>
using namespace std;
const int tam = 1429431;
int st[4*tam];

void build(int p, int L , int R) {
    if(L == R) {
        st[p] = (L&1);
    } else {
        int mid = ((L + R) >> 1), left = (p<<1);
        build(left, L, mid);
        build(left+1, mid+1, R);
        st[p] = st[left] + st[left+1];
    }
}
 
void update(int p, int L, int R, int pos) {
    if(L == R) { st[p] = 0; return; }
    int mid = (L + R)>>1, left = p<<1;
    if( st[left] < pos) update(left+1, mid+1, R, pos - st[left]);
    else update(left, L, mid, pos);
    st[p] = st[left] + st[left+1];
}

int query(int p, int L, int R, int pos) {
    if(L == R) return R;
    int mid = (L + R) >> 1, left = p<<1;
    if(st[left] < pos) return query(left+1, mid+1, R, pos - st[left]);
    else  return query(left, L, mid, pos);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t, n;
    build(1, 0, tam);
    int x = 3;
    for(int i=2; x < st[1]; i++) {
        x = query(1, 0, tam, i);
        int xx = x;
        while(xx <= st[1]) {
            //cout << xx << '\n';
            update(1, 0, tam, xx);
            xx += x - 1;
        }
    }
    cin >> t; 
    for(int r = 1; r <= t; r++) {
        cout << "Case " << r << ": ";
        cin >> n;
        cout << query(1, 0, tam, n) << '\n';
    }
    return 0;
}