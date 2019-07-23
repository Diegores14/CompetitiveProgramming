#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, temp = 1e9;
    cin >> n;
    long long ans = 0;
    int cant = 10;
    while(temp != 1) {
        if(n >= temp) {
            //cout << (n/temp - 1) * temp + n%(temp) + 1 << ' ' << cant << '\n';
            ans += ((n/temp - 1) * temp + n%(temp) + 1) * cant;
            n -= ((n/temp - 1) * temp + n%(temp) + 1);
        }
        temp /= 10;
        cant--;
    }
    cout << ans + n << '\n';
    return 0;
}