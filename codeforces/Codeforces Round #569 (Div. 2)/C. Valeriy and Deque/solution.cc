#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    n--;
    long long mmax = 0, temp;
    list<long long> l;
    long long ans[n][2];
    for(int i = 0; i <= n; i++) {
        cin >> temp;
        mmax = max(mmax, temp);
        l.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        int a, b;
        a = l.front();
        l.pop_front();
        b = l.front();
        l.pop_front();
        ans[i][0] = a;
        ans[i][1] = b;
        if(a > b) {
            l.push_front(a);
            l.push_back(b);
        } else {
            l.push_front(b);
            l.push_back(a);
        }
    }
    long long v[n];
    l.pop_front();
    for(int i = 0; i < n; i++) {
        v[i] = l.front();
        l.pop_front();
    }
    while(q--) {
        cin >> temp;
        temp--;
        if(temp < n) {
            cout << ans[temp][0] << ' ' << ans[temp][1] << '\n';
        } else {
            cout << mmax << ' ' << v[temp%n] << '\n';
        }
    }
    return 0;
}