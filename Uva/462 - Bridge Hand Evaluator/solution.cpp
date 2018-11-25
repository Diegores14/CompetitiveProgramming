#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    vector<string> v(13);
    map<char, int> altas, cards;
    vector<char> order({'S', 'H', 'D', 'C'});
    altas['A'] = 4;
    altas['J'] = 1;
    altas['Q'] = 2;
    altas['K'] = 3;
    cards['A'] = 1;
    cards['K'] = 2;
    cards['Q'] = 3;
    cards['J'] = 4;
    while(cin >> s){
        map<char, int> suit;
        set<char> stopped;
        int mmax = 1;
        v[0] = s;
        suit[s[1]]++;
        long long cant = 0;
        for(int i=1; i<13; i++){
            cin >> s;
            v[i] = s;
            suit[s[1]]++;
            mmax = max(mmax, suit[s[1]]);
        }
        // cout << "Hello 1\n";
        for(string i: v){
            if(altas.count(i[0])){
                cant += altas[i[0]];
                if(i[0] != 'J' && suit[i[1]] >= cards[i[0]]){
                    stopped.insert(i[1]);
                }
            }
        }
        for(string i: v){
            if(altas.count(i[0])){
                if(i[0] != 'A' && suit[i[1]] < cards[i[0]]){
                    cant--;
                }
            }
        }
        // cout << "Hello 2\n";
        if(cant >= 16 && stopped.size() == 4){
            cout << "BID NO-TRUMP\n";
            continue;
        }
        // cout << "Hello 3\n";
        for(auto i: suit){
            if(i.second == 2)
                cant++;
            if(i.second == 1)
                cant += 2;
        }
        cant += (4 - suit.size())<<1;
        // cout << "Hello 4\n";
        if(cant < 14){
            cout << "PASS\n";
        }else{
            cout << "BID ";
            for(char i: order){
                if(suit.count(i) && suit[i] == mmax){
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}