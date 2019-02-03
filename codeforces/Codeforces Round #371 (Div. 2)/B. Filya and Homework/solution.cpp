#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, mmin = 1000000000, mmax = 0;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for(int &i: v) {
        cin >> i;
        s.insert(i);
        mmin = min(mmin, i);
        mmax = max(mmax, i);
    }
    int x = (mmax - mmin + 1)>>1;
    int mid = (mmax + mmin + 1)>>1;
    if(s.size() == 2) {
        cout << "YES\n";
        return 0;
    }
    for(int i: v) {
        if(i == mid) {
            continue;
        }
        if(i<mid) {
            if(i+x != mid) {
                cout << "NO\n";
                return 0;
            }
        } else {
            if(i-x != mid) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}