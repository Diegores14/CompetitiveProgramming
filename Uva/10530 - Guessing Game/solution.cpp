#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r = 11, l= -1, n;
    string s;
    while(cin >> n, n){
        cin.ignore();
        getline(cin, s);
        if(s == "too high"){
            r = min(r, n);
        }
        if(s == "too low"){
            l = max(n, l);
        }
        if(s == "right on"){
            if(n <= l || r <= n){
                cout << "Stan is dishonest\n";
            }else{
                cout << "Stan may be honest\n";
            }
            l = -1;
            r = 11;
        }
    }
    return 0;
}