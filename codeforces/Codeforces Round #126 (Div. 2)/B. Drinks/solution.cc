#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, sum = 0, temp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << fixed << setprecision(10) << (long double)sum / n << '\n';
    return 0;
}