#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a;
    string s;
    cin >> a >> s;
    if( a >= 3200) {
        cout << s << '\n';
    } else {
        cout << "red\n";
    }
    return 0;
}