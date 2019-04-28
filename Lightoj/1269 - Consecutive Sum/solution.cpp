#include <bits/stdc++.h>
using namespace std;
const int tam = 50005*33;


struct trie {
    int m[tam][2];
    int nodes;
    void clear() { 
        memset(m, -1, sizeof m);
        nodes = 1;
    }
    void add(int s) {
        int curr = 0;
        for(int idx = 31; idx >= 0; idx--) {
            int next = (s>>idx)&1;
            if(m[curr][next] == -1) {
                m[curr][next] = nodes++;
            }
            curr = m[curr][next];
        }
    }
    int getMax(int s) {
        int ans = 0, curr = 0;
        for(int idx = 31; idx >= 0; idx--){
            int next = ((s>>idx)&1);
            if( m[curr][next^1] != -1) {
                ans |= 1<<idx;
                curr = m[curr][next^1];
            } else {
                curr = m[curr][next^0];
            }
        }
        return ans;
    }
    int getMin(int s, int idx = 31) {
        int ans = 0, curr = 0;
        for(int idx = 31; idx >= 0; idx--) {
            int next = ((s>>idx)&1);
            if(m[curr][next^0] != -1) {
                curr = m[curr][next^0];
            } else {
                ans |= 1<<idx;
                curr = m[curr][next^1];
            }
        }
        return ans;
    }
};

trie tree;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, temp, acc, mmin, mmax;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case " << k << ": ";
        cin >> n;
        cin >> temp;
        mmin = temp;
        mmax = temp;
        acc = temp;
        tree.clear();
        tree.add(acc);
        tree.add(0);
        for(int i=1; i<n; i++) {
            cin >> temp;
            acc ^= temp;
            //cout << acc << '\n';
            //cout << tie.getMax(acc) << ' ' << tie.getMin(acc) << '\n';
            mmax = max(mmax, tree.getMax(acc));
            mmin = min(mmin, tree.getMin(acc));
            tree.add(acc);
        }
        cout << mmax << ' ' << mmin << '\n';
    } 
    return 0;
}