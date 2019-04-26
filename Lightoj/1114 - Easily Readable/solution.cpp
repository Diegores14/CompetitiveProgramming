#include <bits/stdc++.h>
using namespace std;

struct trie {
    map<char, trie> m;
    int val;
    trie(): val(0) {}
    void insert(string &s, int idx = 0) {
        //cout << idx << ' ' << s.size() << '\n';
        if(idx == s.size()) {
            val++;
            return;
        }
        m[s[idx]].insert(s, idx+1);
    }
    int search(string s, int idx=0) {
        if(s.size() == idx) {
            return val;
        }
        return m[s[idx]].search(s, idx+1);
    }
};

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    string s;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case " << k << ":\n";
        cin >> n;
        trie dictionary;
        while(n--) {
            //cout << "Debug " << n << '\n';
            cin >> s;
            if(s.size() >= 4) {
                sort(++s.begin(), --s.end());
            }
            dictionary.insert(s);
            //cout << "Debug " << n << '\n';
            
        }
        cin >> n;
        cin.ignore();
        while(n--) {
            getline(cin, s);
            stringstream ss(s);
            long long ans = 1;
            string aux;
            while(ss >> aux) {
                if(aux.size() >= 4) {
                    sort(++aux.begin(), --aux.end());
                }
                //cout << aux << ' ' << dictionary.search(aux) << '\n';
                ans *= dictionary.search(aux);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}