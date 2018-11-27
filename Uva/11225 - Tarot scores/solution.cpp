#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<string, int> cards, values;
    map<int, int> limit;
    vector<string> suit({"diamonds", "clubs", "spades", "hearts"});
    set<string> oudlers;
    cards["king"] = 9;
    cards["queen"] = 7;
    cards["knight"] = 5;
    cards["jack"] = 3;
    limit[0] = 56;
    limit[1] = 51;
    limit[2] = 41;
    limit[3] = 36;
    oudlers.insert("fool");
    oudlers.insert("one of trumps");
    oudlers.insert("twenty-one of trumps");
    for(auto i: cards){
        for(auto j: suit){
            values[i.first + " of " + j] = i.second;
        }
    }
    int t, n;
    cin >> t;
    for(int k=1; k<=t; k++){
        cout << "Hand #" << k << '\n';
        cin >> n;
        string s;
        long long cant = 0, oudl = 0;
        cin.ignore();
        while(n--){
            getline(cin, s);
            if(oudlers.count(s)){
                cant += 9;
                oudl++;
            }else{
                if(values.count(s)){
                    cant += values[s];
                }else{
                    cant++;
                }
            }
        }
        cant >>= 1;
        if(cant >= limit[oudl]){
            cout << "Game won by "<< cant-limit[oudl] << " point(s).\n";
        }else{
            cout << "Game lost by "<< limit[oudl]-cant << " point(s).\n";
        }
        if(k!=t){
            cout << '\n';
        }
    }
    return 0;
}