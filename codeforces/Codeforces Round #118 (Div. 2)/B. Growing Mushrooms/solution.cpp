#include <bits/stdc++.h>
using namespace std;

struct node {
    long long val, idx;
    node(long long val, long long idx): val(val), idx(idx) {}
    bool operator <(node other) const {
        if(val == other.val) {
            return idx > other.idx;
        } else {
            return val < other.val;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, t1, t2, k, a, b;
    cin >> n >> t1 >> t2 >> k;
    cout << fixed << setprecision(2);
    priority_queue<node> q;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        long long temp1 = t1*b*100;
        long long temp2 = t1*a*100;
        q.push(node(max(temp2 - (temp2*k)/100 + t2*b*100, temp1 - (temp1*k)/100 + t2*a*100), i+1));
    }
    while(!q.empty()) {
        node temp = q.top();
        q.pop();
        cout << temp.idx << ' ' << (long double)temp.val/100 << '\n';
    }
    return 0;
}