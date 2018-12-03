#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s;
    cout << fixed << setprecision(4);
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        map<string, int> m;
        long long cont = 0;
        while(getline(cin, s), s != ""){
            m[s]++;
            cont++;
        }
        for(auto & i : m){
            cout << i.first << " " << double(i.second*100)/cont << '\n';
        }
        if(t){        
            cout << '\n';
        }
    }
    return 0;
}