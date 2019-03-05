#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    vector<long long> a(n), b(n);
    long long l = 0;
    for(int &i: a) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
        l = max(l, i);
    }
    long long r = 1e18;
    while(l != r) {
        int mid = (r+l)>>1;
        
    }
    return 0;
}