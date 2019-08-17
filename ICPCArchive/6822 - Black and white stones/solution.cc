#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b;
    string s;
    while( cin >> a >> b ) {
        cin >> s;
        int cant = 0;
        for(char i: s) {
            cant += (i == 'B');
        }
        int i = 0, j = s.size()-1;
        long long ans = 0;
        while( true ) {
            while( cant <= j  && s[j] == 'W') j--;
            while( i < s.size() && s[i] == 'B') i++;
            if(j < cant || i == cant) break;
            //cout << i << ' ' << j << '\n';
            ans += min((a-b)*(j-i), a);
            i++;
            j--;
        }
        cout << ans << '\n';
    }
    return 0;
}