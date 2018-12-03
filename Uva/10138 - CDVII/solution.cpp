#include <bits/stdc++.h>
using namespace std;


struct node
{
    string tiempo, isIntire;
    int value;
    node(){
        value = 0;
    }
    node(int _value, string _t, string intire){
        value = _value;
        tiempo = _t;
        isIntire = intire;
    }
    bool operator <(node &other)const{
        return tiempo < other.tiempo;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, d;
    string a, b, c, s;
    cin >> t;
    cout << fixed << setprecision(2);
    while(t--){
        vector<int> days(24);
        map<string, vector<node> > m;
        for(int i=0; i < 24; i++){
            cin >> days[i];
        }
        cin.ignore();
        while(getline(cin, s), s != ""){
            stringstream aux;
            aux << s;
            aux >> a >> b >> c >> d;
            m[a].emplace_back(node(d, b, c));
        }
        for(auto &i : m){
            long long ans = 0;
            sort(i.second.begin(), i.second.end());
            for(int j=0; j < i.second.size() - 1; j++){
                if(i.second[j].isIntire == "enter" && i.second[j+1].isIntire == "exit"){
                    ans += abs(i.second[j+1].value - i.second[j].value) * days[stoi(i.second[j].tiempo.substr(6,2))] + 100;
                }
            }
            if(ans != 0){
                cout << i.first << " $" << (ans + 200)/100.0 << '\n';
            }
        }
        if(t)
            cout << '\n';
    }
    return 0;
}