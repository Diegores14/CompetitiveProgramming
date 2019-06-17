#include <bits/stdc++.h>
using namespace std;

struct segment {
    int x, y1, y2, value;
    segment(){}
    segment(int x, int y1, int y2, int value): x(x), y1(y1), y2(y2), value(value) {}
    bool operator <(const segment &other) {
        return x < other.x;
    }
};

const int tam = 30000;
segment v[2*tam];
int st[ (tam << 5) ], h[ 2*tam ], lazy[ (tam << 5) ];

void update(int p, int b, int e, int l, int r,int value) {
    //cout << "Update " << b << ' ' << e << '\n';
    if(r < h[b] || h[e] < l) return;
    int mid = (b+e)>>1, left = (p<<1), right = left + 1;
    if(l <= h[b] && h[e] <= r) {
        lazy[p] += value;
        if(lazy[p]) st[p] = h[e]-h[b];
        else st[p] = st[left] + st[right];
    } else {
        if(b + 1 >= e) return;
        update(left, b, mid, l, r, value);
        update(right, mid, e, l, r, value);
        if(lazy[p]) st[p] = h[e]-h[b];
        else st[p] = st[left] + st[right];
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, x1, x2, y1, y2;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        memset(st, 0, sizeof st);
        cin >> n;
        set<int> he;
        int j = 0;
        for(int i = 0; i < n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            v[j++] = segment(x1, y1, y2, 1);
            v[j++] = segment(x2, y1, y2, -1);
            he.insert(y1);
            he.insert(y2);
        }
        sort(v, v+j);
        int l = 0;
        for(set<int>::iterator it = he.begin(); it != he.end(); ++it) {
            h[l++] = *it;
        }
        long long ans = 0;
        int x = v[0].x;
        for(int i = 0; i < j; i++) {
            //cout << st[1] << ' ' << v[i].x << ' ' << v[i].y1 << ' ' << v[i].y2 << ' ' << v[i].value << '\n';
            ans += 1LL * st[1] * (v[i].x - x);
            x = v[i].x;
            update(1, 0, l-1, v[i].y1, v[i].y2, v[i].value);
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}