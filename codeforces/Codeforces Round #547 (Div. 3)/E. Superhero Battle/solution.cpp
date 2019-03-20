#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long H, n, mmin = 0, temp = 0;
    cin >> H >> n;
    int v[n];
    for(int &i: v) {
        cin >> i;
        temp += i;
        mmin = min(mmin, temp);
    }
    if(H <= abs(mmin)) {
        for(int i=0; i<n; i++) {
            H += v[i];
            if(H <= 0) {
                cout << i+1 << '\n';
                break;
            }
        }
        return 0;
    }
    if(temp < 0) {
        temp *= -1;
        mmin = 1e18;
        for(int i=0; i<n; i++) {
            H += v[i];
            mmin = min(mmin, n*((H+temp-1)/temp) + i + 1);
        }
        cout << mmin << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}