#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    string s;
    while(cin >> n){
        cin >> m;
        set<int> wakeUp;
        vector<list<int>> v(27);
        vector<int> brain(27, 0);
        cin >> s;
        for(char i : s){
            wakeUp.insert(i - 'A');
            n--;
        }
        for(int i = 0; i < m; i++){
            cin >> s;
            v[s[0] - 'A'].push_back(s[1] - 'A');
            v[s[1] - 'A'].push_back(s[0] - 'A');
            if(wakeUp.count(s[0] - 'A')){
                brain[s[1] - 'A']++;
            }
            if(wakeUp.count(s[1] - 'A')){
                brain[s[0] - 'A']++;
            }
        }
        int old=300, ans = 0;
        while(n && n != old){
            ans++;
            old = n;
            list<int> aux;
            for(int i=0; i<27; i++){
                if(brain[i] >= 3 && wakeUp.count(i) == 0){
                    wakeUp.insert(i);
                    n--;
                    aux.push_back(i);
                }
            }
            for(int i : aux){
                for(int j : v[i]){
                    brain[j]++;
                }
            }
            aux.clear();
        }
        if(n == 0){
            cout << "WAKE UP IN, " << ans << ", YEARS\n";
        }else
            cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    return 0;
}