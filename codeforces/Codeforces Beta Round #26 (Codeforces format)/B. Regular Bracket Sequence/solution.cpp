#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int cont = 0, ans = 0;
    cin >> s;
    for(char &i: s) {
        if(i == '(') {
            cont++;
        } else {
            cont--;
            if(cont < 0) {
                cont = 0;
            } else {
                ans++;
            }
        }
    }
    cout << ans*2 << '\n';
    return 0;
}