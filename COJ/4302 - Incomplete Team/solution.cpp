#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    return b? GCD(b, a%b) : a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        cout << (a * b)/ GCD(a, b) << '\n';
    }
    return 0;
}