#include <bits/stdc++.h>
using namespace std;

struct trie {
    int value;
    map<char, trie> m;
    trie() { value = 0;}
    void insert(string &s, int idx = 0) {
        if(idx != 0) value++;
        if(idx == s.size()) {
            return;
        }
        m[s[idx]].insert(s, idx+1);
    }
    int DFS() {
        int ans = 0;
        for(auto &i: m) {
            ans += i.second.DFS();
        }
        if(ans+1<value) {
            ans += 2;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case #" << k << ": ";
        int n;
        cin >> n;
        string s;
        trie tr;
        for(int i = 0; i<n; i++) {
            cin >> s;
            reverse(s.begin(), s.end());
            tr.insert(s);
        }
        cout << tr.DFS() << '\n';
    }
    return 0;
}