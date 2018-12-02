#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    cin >> t;
    cin.ignore();
    cin.ignore();

    while(t--){
        string s, ans;
        int  mmax = -1;
        map<string, int> cont;
        vector<string> v;
        while(getline(cin, s), s != ""){
            v.emplace_back(s);
        }
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(j!=i){
                    cont[v[i]+v[j]]++;
                }
            }
        }
        for(auto i: cont){
            if(i.second > mmax){
                mmax = i.second;
                ans = i.first;
            }
        }
        cout << ans << '\n';
        if(t)
            cout << '\n';
    }
    return 0;
}