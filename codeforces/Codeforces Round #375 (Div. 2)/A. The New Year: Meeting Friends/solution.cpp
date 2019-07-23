#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int mmax = 0, mmin = 100, temp;
    for(int i = 0; i < 3; i++) {
        cin >> temp;
        mmax = max(mmax, temp);
        mmin = min(mmin, temp);
    }
    cout << mmax - mmin << '\n';

    return 0;
}