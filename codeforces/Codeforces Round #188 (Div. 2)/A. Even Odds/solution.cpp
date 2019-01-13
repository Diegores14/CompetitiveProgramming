#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    long long limit = n/2 + (n&1LL);
    if(k <= limit) {
        cout << (k<<1) - 1  << '\n';
    } else {
        cout << ((k-limit)<<1) << '\n';
    }
    return 0;
}