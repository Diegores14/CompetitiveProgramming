#include <bits/stdc++.h>
using namespace std;
map<char, int> order;

struct node{
    string s;
    node(){}
    node(string _s){ s = _s;}
};

bool operator <(node s1, node s2){
    if(order[s1.s[0]] == order[s2.s[0]])
        return order[s1.s[1]] < order[s2.s[1]];
    else
        return order[s1.s[0]] < order[s2.s[0]];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<char, int> position;
    order['C'] = 1;
    order['D'] = 2;
    order['S'] = 3;
    order['H'] = 4;
    order['2'] = 1;
    order['3'] = 2;
    order['4'] = 3;
    order['5'] = 4;
    order['6'] = 5;
    order['7'] = 6;
    order['8'] = 7;
    order['9'] = 8;
    order['T'] = 9;
    order['J'] = 10;
    order['Q'] = 11;
    order['K'] = 12;
    order['A'] = 13;
    position['S'] = 1;
    position['W'] = 2;
    position['N'] = 3;
    position['E'] = 4;
    char dealer;
    while(cin >> dealer, dealer != '#'){
        cin.ignore();
        int n = position[dealer];
        vector< vector<node> > v(4);
        string s;
        getline(cin, s);
        int j=0;
        for(int i=0; i<s.size(); i += 2){
            v[(j+n)%4].emplace_back(node(s.substr(i, 2)));
            j++;
        }
        getline(cin, s);
        for(int i=0; i<s.size(); i += 2){
            v[(j+n)%4].emplace_back(node(s.substr(i, 2)));
            j++;
        }
        for(auto &i : v)
            sort(i.begin(), i.end());
        cout << "S:";
        for(int i=0; i<13; i++)
            cout << ' ' << v[0][i].s;
        cout << "\nW:";
        for(int i=0; i<13; i++)
            cout << ' ' << v[1][i].s;
        cout << "\nN:";
        for(int i=0; i<13; i++)
            cout << ' ' << v[2][i].s;
        cout << "\nE:";
        for(int i=0; i<13; i++)
            cout << ' ' << v[3][i].s;
        cout << '\n';
    }
    return 0;
}