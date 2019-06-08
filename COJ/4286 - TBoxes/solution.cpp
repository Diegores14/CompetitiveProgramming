#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int mmin = 1e9, mmax = 0, temp;
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> temp;
        mmin = min( mmin, temp );
        mmax = max( mmax, temp );
        cout << mmax + mmin << '\n';
    }
    return 0;
}