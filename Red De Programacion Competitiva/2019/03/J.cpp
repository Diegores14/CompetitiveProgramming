#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, s;
    int mmax = 0;
    int temp;
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> temp;
        mmax = max(mmax, temp);
    }
    cout << (mmax*s + 999)/1000 << '\n';
    return 0;
}