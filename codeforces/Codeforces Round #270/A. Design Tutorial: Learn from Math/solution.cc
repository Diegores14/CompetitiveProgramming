#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n&1) {
        int a = n/3;
        cout << 9 << ' ' << n-9 << '\n';
    }
    else {
        int a = n/2;
        cout << n-4 << ' ' << 4  << '\n';
    }
    return 0;
}