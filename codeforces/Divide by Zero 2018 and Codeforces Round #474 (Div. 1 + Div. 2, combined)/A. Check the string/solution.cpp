#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int cont1 = 0, cont2 = 0, cont3 = 0;
    int i = 0;
    for(; i<s.size() && s[i] == 'a'; i++){
        cont1++;
    }
    for(; i<s.size() && s[i] == 'b'; i++){
        cont2++;
    }
    for(; i<s.size() && s[i] == 'c'; i++){
        cont3++;
    }
    //cout << cont1 << ' ' << cont2 << ' ' << cont3 << '\n';
    if(cont1 == 0 || cont2 == 0 || i != s.size()){
        cout << "NO\n";
    } else {
        if(cont1 == cont3 || cont2 == cont3){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}