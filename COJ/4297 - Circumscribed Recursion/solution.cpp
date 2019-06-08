#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    long long R, k;
    while(t--) {
        cin >> R >> k; 
        if(k&1) {
            cout << (1ULL<<(k/2)) * R * R << "PI\n";
        } else {
            cout << 4 * (1ULL<<(k/2 - 1)) * R * R << '\n';
        }
    }
    return 0;
}