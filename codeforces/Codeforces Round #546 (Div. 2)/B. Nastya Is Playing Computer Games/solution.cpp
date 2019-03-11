#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    cout << 3*n  + min(n-k, k-1) << '\n'; 
    return 0;
}