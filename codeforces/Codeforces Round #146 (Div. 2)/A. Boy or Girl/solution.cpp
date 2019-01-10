#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<char> s;
    string temp;
    cin >> temp;
    for(char i: temp) {
        s.insert(i);
    }
    if(s.size()%2 == 0)
        cout << "CHAT WITH HER!\n";
    else
        cout << "IGNORE HIM!\n";
    return 0;
}