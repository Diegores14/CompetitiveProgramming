#include <bits/stdc++.h>
using namespace std;
map<string, int> s;

int solution(string name, map<string, vector<string>> & parents, map<string, string> & ans){
    if(ans.count(name))
        return s[ans[name]];
    int aux = 0;
    for(auto i : parents[name]){
        aux += solution(i, parents, ans);
    }
    if(aux == 2){
        ans[name] = "recessive";
    }else{
        if(aux >= 3)
            ans[name] = "dominant";
        else
            ans[name] = "non-existent";
    }
    return s[ans[name]];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);    
    map<string, vector<string>> parents;
    map<string, string> ans;
    s["dominant"] = 2;
    s["non-existent"] = 0;
    s["recessive"] = 1;
    string a, b;
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> a >> b;        
        if(s.count(b)){
            ans[a] = b;
        }else{
            parents[b].emplace_back(a);
        }
    }
    for(auto &i : parents){
        if(!ans.count(i.first)){
            solution(i.first, parents, ans);
        }
    }
    for(auto &i : ans){
        cout << i.first << ' ' << i.second <<'\n';
    }
    return 0;
}