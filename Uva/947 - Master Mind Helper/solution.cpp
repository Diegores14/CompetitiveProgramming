#include <bits/stdc++.h>
using namespace std;
map<char, int> m;

int solve(const string & s, string & aux, int idx, const int &a, const int &b){
    if(idx == s.size()){
        int contA = 0, contB = 0;
        map<char, int> match;
        for(int i=0; i<s.size(); i++){
            if(s[i]==aux[i]){
                match[s[i]]++;
                contA++;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]!=aux[i]){
                if(m.count(aux[i]) && m[aux[i]] > match[aux[i]]){
                    contB++;
                    match[aux[i]]++;
                }
            }
        }
        if(contA == a && contB == b)
            return 1;
        else
            return 0;
    }else{
        int cont = 0;
        for(int i=1; i<10; i++){
            aux[idx] = '0' + i;
            cont += solve(s, aux, idx+1, a, b);
        }
        return cont;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n;
    while(n--){
        string s, aux;
        cin >> s >> a >> b;
        m.clear();
        for(char &i: s){
            m[i]++;
            aux.push_back('0');
        }
        cout << solve(s, aux, 0, a, b) << '\n';
    }
    return 0;
}