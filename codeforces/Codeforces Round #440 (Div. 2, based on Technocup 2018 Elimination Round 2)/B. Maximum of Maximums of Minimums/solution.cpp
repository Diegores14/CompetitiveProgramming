#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, mmax = -1e9, mmin = 1e9;
    cin >> n >> k;
    vector<int> v(n);
    for(int &i: v){
        cin >> i;
        mmax = max(mmax, i);
        mmin = min(mmin, i);
    }
    if (k == 1) {
        cout << mmin << '\n';
    }else {
        if (k == 2) {
            cout << max(v[0], v[n-1]) << '\n';
        }else {
            cout << mmax << '\n';
        }
    }
    return 0;
}