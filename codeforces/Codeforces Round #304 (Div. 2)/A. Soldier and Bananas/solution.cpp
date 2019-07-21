#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long k, n, w;
    cin >> k >> n >> w;
    cout << max(0LL, k*(w*(w+1))/2 - n) << '\n';
    return 0;
}