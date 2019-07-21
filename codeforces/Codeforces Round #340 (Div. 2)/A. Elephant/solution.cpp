#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long x;
    cin >> x;
    cout << x/5 + (x%5? 1 : 0) << '\n';
    return 0;
}