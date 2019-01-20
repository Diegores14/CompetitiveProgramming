#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p; 
    cin >> p;
    int n, k;
    while(p--) {
        cin >> k >> n;
        cout << k << ' ' << ((n*(n+1)) >> 1 ) + n << '\n'; 
    }
    return 0;
}