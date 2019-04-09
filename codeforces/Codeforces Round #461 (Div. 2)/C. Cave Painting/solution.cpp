#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b? gcd(b, a%b) : a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    for(int i=1; i<=k; i++) {
        if(n%i != i-1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}