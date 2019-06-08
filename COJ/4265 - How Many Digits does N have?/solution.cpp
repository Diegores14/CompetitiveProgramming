#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    int a, b;
    while(t--) {
        cin >> a >> b;
        cout << int(a * log10(2) + b * log10(5)) + 1 << '\n';
    }
    return 0;
}