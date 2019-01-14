#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin >> n;
    if(n&1) {
        cout << (n>>1) - n << '\n';
    } else {
        cout << (n>>1) << '\n';
    }
    return 0;
}