#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, l, c;
    while(cin >> n) {
        l = 1;
        c = 1;
        while( l%n ) {
            c++;
            l = (l*10 + 1)%n;
        }
        cout << c << '\n';
    }
    return 0;
}