#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int cont1=0, cont2=0, cont3=0;
    for(char &i: s) {
        if(i=='1')
            cont1++;
        if(i=='2')
            cont2++;
        if(i=='3')
            cont3++;
    }
    int i=0;
    while(cont1--) {
        s[i] = '1';
        i += 2;
    }
    while(cont2--) {
        s[i] = '2';
        i += 2;
    }
    while(cont3--) {
        s[i] = '3';
        i += 2;
    }
    cout << s << '\n';
    return 0;
}