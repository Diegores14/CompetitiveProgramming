#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int k=0;
    while(cin >> n, n){
        cout << "Game " << ++k << ":\n";
        vector<int> v(n, 0), code(n);
        map<int, int> m;
        for(int &i: code){
            cin >> i;
            m[i]++;
        }
        while(true){
            map<int,int> aux;
            int match = 0, weak = 0;
            for(int i=0; i<n; i++){
                cin >> v[i];
                if(v[i] == code[i]){
                    aux[v[i]]++;
                    match++;
                }
            }
            if(v[0] == 0)
                break;
            for(int i=0; i<n; i++){
                if(v[i] != code[i] && m.count(v[i]) && m[v[i]] > aux[v[i]]){
                    aux[v[i]]++;
                    weak++;
                }
            }
            cout << "    (" << match << ',' << weak << ")\n";
        }
    }
    return 0;
}