#include <bits/stdc++.h>
using namespace std;
map<char, string> names;

void print(vector<string> &v){
    for(auto i: v){
        if(! names.count(i[0]))
            cout << i.substr(0, i.size()-1);
        else
            cout << names[i[0]];
        cout << " of " << ((i[1] == '0')? names[i[2]] : names[i[1]]) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    names['J'] = "Jack";
    names['Q'] = "Queen";
    names['K'] = "King";
    names['A'] = "Ace";
    names['H'] = "Hearts";
    names['S'] = "Spades";
    names['C'] = "Clubs";
    names['D'] = "Diamonds";
    string s;
    vector<string> cardsValue({"2","3","4","5","6","7","8","9","10","J","Q","K","A"});
    set<string> suits;
    suits.insert("H");
    suits.insert("S");
    suits.insert("C");
    suits.insert("D");
    cin >> t;
    while(t--){
        vector<string> deck(52);
        int k = 0;
        for(auto i: suits){
            for(auto j: cardsValue){
                deck[k] = (j + i); 
                k++;
            }
        }
        int cant;
        cin >> cant;
        vector< vector<int> > v(cant, vector<int>(52));
        for(int i=0; i<cant; i++){
            for(int j=0; j < 52; j++){
                cin >> v[i][j];
                v[i][j]--;
            }
        }
        vector<string> ans(52);
        cin.ignore();
        while(getline(cin, s) && s.size() != 0){
            vector<string> aux(52);
            k = stoi(s);
            k--;
            for(int i=0; i<52; i++){
                aux[i] = deck[v[k][i]];
            }
            deck = aux;
        }
        print(deck);
        if(t)
            cout << '\n';
    }
    return 0;
}