#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, cont1 = 0, cont2 = 0;
    string s;
    cin >> n >> s;
    for(int i=0; i<n; i++){
        if(s[i] == 'A')
            cont1++;
        else
            cont2++;
    }
    if(cont1 == cont2)
        cout << "Friendship\n";
    else{
        if(cont1 > cont2)
            cout << "Anton\n";
        else
            cout << "Danik\n";
    }
    return 0;
}