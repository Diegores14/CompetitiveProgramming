#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(string s){
    int n = s.size()>>1;
    for(int i=0; i<=n; i++){
        if(s[i]!=s[s.size()-i-1])
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        map<char, int> m;
        if(!isPalindrom(s)){
            cout << s << '\n';
        }else{
            for(int i=0; i<s.size(); i++){
                m[s[i]] = i;
            }            
            if(m.size()>1){
                map<char, int>::iterator it = m.begin();
                int a = it->second;
                it++;
                int b = it->second;
                swap(s[a], s[b]);
                cout << s << '\n';
            }else{
                cout << "-1\n";
            }
        }
    }
    return 0;
}