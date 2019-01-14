#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    if(n == 1 && k == 10) {
        cout << "-1\n";
    } else {
        cout << k;
        if(k == 10) {
            n -= 2;
        } else {
            n--;
        }
        for(int i=0; i<n; i++) {
            cout << "0";
        }
        cout << '\n';
    }
    return 0;
}