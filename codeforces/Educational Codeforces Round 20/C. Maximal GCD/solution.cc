#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    if(k >= 200000) {
        cout << -1 << '\n';
        return 0;
    }
    long long temp = k*(k-1)/2;
    for(long long i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            long long a = n/i;
            //cout << n - temp*i << ' ' << temp*i << '\n';
            if(n - temp*i > (k-1)*i) {
                ans = max(ans, i);
            }
            if((long double)n/(k-1) - (long double)(k*a)/2 > a) {
                ans = max(ans, a);
            }
        }
    }
    if(ans) {
        long long sum = 0;
        for(int i = 1; i < k; i++) {
            sum += i*ans;
            cout << i*ans << ' ';
        }
        cout << n - sum << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}