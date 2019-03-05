#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v[4];
    for(int &i: v) {
        cin >> i;
    }
    if(v[0] == v[3]) {
        if((v[2] && v[0]) || v[2] == 0) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else {
        cout << 0 << '\n';
    }
    return 0;
}