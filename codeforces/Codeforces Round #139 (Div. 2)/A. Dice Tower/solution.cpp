#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int temp, k1 = 7 - k;
    n <<= 1;
    for(int i = 0; i<n; i++) {
        cin >> temp;
        if(temp == k || temp == k1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}