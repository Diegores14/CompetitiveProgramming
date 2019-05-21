#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t;
    string s;
    cin >> t;
    for(int r=1; r <= t; r++) {
        cin >> n >> s;
        cout << "Case " << r << ": ";
        if(s[0] == 'A')
            cout << ((n%3 == 1)? "Bob" : "Alice") << '\n';
        else 
            cout << ((n%3 == 0)? "Alice" : "Bob") << '\n';
    }
    return 0;
}