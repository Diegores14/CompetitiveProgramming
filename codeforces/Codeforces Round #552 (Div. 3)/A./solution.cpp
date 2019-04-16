#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long mmin = 1e9, mmax = 0;
    long long sum = 0; 
    vector<long long> v(4);
    for(long long &i: v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    cout << v[3] - v[0] << ' ' << v[3] - v[1] << ' ' << v[3] - v[2] << '\n';
    return 0;
}