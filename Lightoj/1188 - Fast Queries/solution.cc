#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int tam = 1e5+5;
int st[4*tam], last[tam];

void update(int node, int b, int e, int l, int v) {
    if(l < b || e < l) return;
    if( b == e ) {
        st[node] += v;
    } else {
        int mid = (b + e)>>1, left = (node<<1), right = left + 1;
        update(left, b, mid, l, v);
        update(right, mid+1, e, l, v);
        st[node] = st[left] + st[right];
    }
}

int query(int node, int b, int e, int l, int r) {
    if(r < b || e < l) return 0;
    if( l <= b && e <= r ) {
        return st[node];
    } else {
        int mid = (b + e)>>1, left = (node<<1), right = left + 1;
        return query(left, b, mid, l, r) + query(right, mid+1, e, l, r);
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        memset(last, -1, sizeof last);
        memset(st, 0, sizeof st);
        cin >> n >> q;
        int matriz[n];
        for(int &i: matriz) {
            cin >> i;
        }
        iii v[q];
        for(int i = 0; i < q; i++) {
            cin >> v[i].first.second >> v[i].first.first;
            v[i].first.second--;
            v[i].first.first--;
            v[i].second = i;
        }
        sort(v, v+q);
        int j = 0;
        int ans[q];
        for(int i = 0; i < n; i++) {
            if(last[matriz[i]] == -1) {
                last[matriz[i]] = i;
                update(1, 0, n-1, i, 1);
            } else {
                update(1, 0, n-1, last[matriz[i]], -1);
                last[matriz[i]] = i;
                update(1, 0, n-1, i, 1);
            }
            while(j < q && i == v[j].first.first) {
                ans[v[j].second] = query(1, 0, n-1, v[j].first.second, v[j].first.first);
                j++;
            }
        }
        cout << "Case " << cases << ":\n";
        for(int &i: ans) {
            cout << i << '\n';
        }
    }
    return 0;
}