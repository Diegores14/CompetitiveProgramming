#include <bits/stdc++.h>
using namespace std;
const int tam = 30000;
int v[tam], n;
pair<int, int> st[4*tam];

void build(int p, int L, int R) {
    if(L == R) { st[p] = make_pair(v[L], L); return;}
    int mid = (L + R) >> 1, left = p<<1;
    build(left, L, mid);
    build(left+1, mid+1, R);
    st[p] = min(st[left], st[left+1]);
}

pair<int, int> query(int p, int L, int R, int i, int j) {
    if(j < L || R < i) return {1000000000, 1000000000};
    if(i <= L && R <= j) return st[p];
    int mid = (L + R) >> 1, left = p<<1;
    auto a1 = query(left, L, mid, i, j);
    auto a2 = query(left+1, mid+1, R, i, j);
    return min(a1, a2);
}

int solve(int i, int j) {
    if(j < i) return 0;
    auto mmin = query(1, 0, n-1, i, j);
    int a1 = (j-i+1) * mmin.first;
    int a2 = max( solve(i, mmin.second-1), solve(mmin.second+1, j) );
    return max(a1, a2);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    scanf("%d", &t);
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ": ";
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        build(1, 0, n-1);
        cout << solve(0, n-1) << '\n';
    }
    return 0;
}