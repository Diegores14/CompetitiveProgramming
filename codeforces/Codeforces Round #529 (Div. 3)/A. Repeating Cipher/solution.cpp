#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
        cin >> n;
        string s;
        cin >> s;
        int j=1;
        int i=0;
        while(i<s.size()){
            cout << s[i];
            i += j;
            j++;
        }
        cout << '\n';
    return 0;
}