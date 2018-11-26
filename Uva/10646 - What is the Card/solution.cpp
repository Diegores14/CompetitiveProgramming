#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    map<char, int> m;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['T'] = 10;
    m['J'] = 10;
    m['Q'] = 10;
    m['K'] = 10;
    m['A'] = 10;
    cin >> t;
    for(int k=1; k<=t; k++){
        cout << "Case " << k << ": ";
        list<string> l, p;
        string aux;
        for(int i = 0; i < 27; i++){
            cin >> aux;
            l.push_back(aux);
        }
        for(int i = 0; i < 25; i++){
            cin >> aux;
            p.push_back(aux);
        }
        // cout << "leyo\n";
        int y=0;
        for(int i = 0; i < 3; i++){
            aux = l.back();
            l.pop_back();
            y += m[aux[0]];
            int limit = 10 - m[aux[0]];
            for(int j = 0;  j<limit; j++){
                l.pop_back();
            }
        }
        // cout << "quito\n";
        while(!p.empty()){
            l.push_back(p.front());
            p.pop_front();
        }
        // cout << "leyo\n";
        for(int i=1; i < y; i++)
            l.pop_front();
        cout << l.front() << '\n';
        l.clear();
        p.clear();
    }
    return 0;
}