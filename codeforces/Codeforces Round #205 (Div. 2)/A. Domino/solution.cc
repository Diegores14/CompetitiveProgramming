#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a , b;
    int paridad1 = 0, paridad2 = 0;
    bool diferent = false;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        if((a+b)&1) diferent = true;
        paridad1 ^= (a&1)? 1 : 0;
        paridad2 ^= (b&1)? 1 : 0;
    }
    if(paridad1 == paridad2) {
        if(paridad1 == 0) {
            cout << 0 << '\n';
        } else {
            if(diferent) {
                cout << 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}