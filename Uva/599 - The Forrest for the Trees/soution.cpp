#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--){
        int E = 0, acorn = 0;
        vector<bool> v(26, false);
        while(cin >> s, s[0] != '*'){
            v[s[1] - 'A'] = true;
            v[s[3] - 'A'] = true;
            E++;
        }
        cin >> s;
        for(int i = 0; i < s.size(); i += 2){
            if(v[s[i]-'A'] == false)
                acorn++;
        }
        cout << "There are " << (s.size()/2 + 1) - E - acorn  << " tree(s) and " << acorn << " acorn(s).\n";
    }
    return 0;
}