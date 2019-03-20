#include <bits/stdc++.h>
using namespace std;
long long ans[1000000];
bool used[1000000];
int n;

bool check() {
    for(int i=0; i<n; i++) {
        if(ans[i] <= 0 || n < ans[i]) {
            return false;
        }
        if(used[ans[i]]) {
            return false;
        }
        used[ans[i]] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(used, 0, sizeof used);
    long long mmin = 0;
    int q[n-1];
    for(int &i: q) {
        cin >> i;
    }
    ans[0] = 0;
    for(int i=1; i<n; i++) {
        ans[i] = q[i-1] + ans[i-1];
        mmin = min(mmin, ans[i]);
    }
    mmin = abs(mmin) + 1;
    for(int i=0; i<n; i++) {
        ans[i] += mmin;
    }
    if(check()) {
        for(int i=0; i<n; i++) {
            cout << ans[i] << (i==n-1? '\n' : ' ');
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}