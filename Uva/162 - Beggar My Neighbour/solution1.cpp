#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    map<char, int> m;
    m['J'] = 1;
    m['Q'] = 2;
    m['K'] = 3;
    m['A'] = 4;
    while(true){
        list<char> players[2], pila;
        for(int i=0; i<52; i++){
            cin >> s;
            if(s == "#")
                return 0;
            players[i&1].emplace_front(s[1]);
        }
        int turn = 0;
        int cant = 0;
        while(true){
            if(players[turn&1].empty())
                break;
            char aux = players[turn&1].front();
            players[turn&1].pop_front();
            pila.emplace_back(aux);
            if(m.count(aux)){
                cant = m[aux] + 1;
                turn++;
            }
            if(cant > 0){
                cant--;
                if(!cant){
                    turn++;
                    while(!pila.empty()){
                        players[turn&1].emplace_back(pila.front());
                        pila.pop_front();
                    }
                }
            }else{
                turn++;
            }
        }
        if(turn&1){
            cout << "2 " << (players[0].size()<10? " " : "") << players[0].size() << '\n';
        }
        else
            cout << "1 " << (players[1].size()<10? " " : "") << players[1].size() << '\n';
    }
    return 0;
}