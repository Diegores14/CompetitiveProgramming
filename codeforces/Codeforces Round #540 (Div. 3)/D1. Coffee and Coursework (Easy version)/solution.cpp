#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long total = 0;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
        total += i;
    }
    if(total < m) {
        cout << -1 << '\n';
    } else {
        int ans = 0;
        long long temp;
        do {
            ans++;
            temp = (-1+sqrt(1+8*(total-m)))/2;
            total -= (temp*(temp+1))>>1;
            m -= (temp*(temp+1))>>1;
        } while(m > 0 && temp);
        cout << ans << '\n';
    }
    return 0;
}