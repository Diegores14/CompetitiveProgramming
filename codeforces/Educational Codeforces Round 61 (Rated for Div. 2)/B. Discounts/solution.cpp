#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp;
    cin >> n;
    long long sum = 0;
    vector<long long> v(n);
    for(long long &i: v) {
        cin >> i;
        sum += i;
    }
    sort(v.begin(), v.end());
    cin >>m;
    while(m--) {
        cin >> temp;
        cout << sum - v[n-temp] << '\n';
    }
    return 0;
}