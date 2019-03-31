#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    long long sum = 0;
    cin >> n;
    vector<int> v[2];
    for(int i=0; i<n; i++) {
        cin >> temp;
        sum += temp;
        v[(temp&1)].emplace_back(temp);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    int l = (int)v[0].size()-1, r = (int)v[1].size()-1;
    int turn = (l >= r);
    while(true) {
        if(turn) {
            if(l < 0) {
                break;
            }
            sum -= v[0][l--];
        } else {
            if(r < 0) {
                break;
            }
            sum -= v[1][r--];
        }
        turn ^= 1;
    }
    cout << sum << '\n';
    return 0;
}