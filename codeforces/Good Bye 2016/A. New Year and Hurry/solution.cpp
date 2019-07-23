#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int l = 0, r = n+1;
    while(r-l != 1) {
        int mid = (l+r)>>1;
        if(5 * ( mid*(mid+1) )/2 + k <= 240) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
    return 0;
}