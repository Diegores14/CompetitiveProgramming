#include <bits/stdc++.h>
using namespace std;
int f[26];

struct trie {
    trie* m[4];
    int val;
    trie() {
        val = 0;
        m[0] = NULL;
        m[1] = NULL;
        m[2] = NULL;
        m[3] = NULL;
    }
    void insert(string s, int idx = 0) {
        val++;
        if(idx == s.size()) {
            return;
        }
        int ind = f[s[idx]-'A'];
        if(m[ind] == NULL) m[ind] = new trie();
        m[ind]->insert(s, idx+1);
    }

    int DFS(int len = 0) {
        int ans = len*val;
        for(auto &i: m) {
            if(i != NULL)
                ans = max(ans, i->DFS(len+1));
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    int r = 0;
    for(char i: {'A', 'C', 'G', 'T'}) {
        f[i-'A'] = r++;
    }
    string s;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case " << k << ": ";
        cin >> n;
        trie setDNA;
        while(n--) {
            cin >> s;
            setDNA.insert(s);
        }
        cout << setDNA.DFS() << '\n';
    }
    return 0;
}