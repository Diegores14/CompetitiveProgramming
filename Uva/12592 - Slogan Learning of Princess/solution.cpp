#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n;
    string s1, s2;
    map<string, string> slogans;
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, s1);
        getline(cin, s2);
        slogans[s1] = s2;
    }
    cin >> q;
    cin.ignore();
    for(int i=0; i<q; i++){
        getline(cin, s1);
        cout << slogans[s1] << '\n';
    }
    return 0;
}