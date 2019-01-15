#include <bits/stdc++.h>
using namespace std;
long long n, m;

long long cant (long long n) {
    long long ans = 0;
    while(n) {
        ans += n&1;
        n >>= 1;
    }
    return ans;
}

long long GCD(long long a, long long b) {
    if(a==0)
        return b;
    return GCD(b%a, a);
}

long long mcm(long long a, long long b) {
    return (a*b)/GCD(a,b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t;
    cin >> t;
    for(long long k=1; k<=t; k++) {
        cin >> n >> m;
        long long ans = 0;
        vector<long long> v(m);
        for(long long i=0; i<m; i++) {
            cin >> v[i];
        }
        for(long long i=1; i < (1<<m); i++) {
            long long mul = 1;
            for(long long j=0; j<m; j++) {
                if((i>>j)&1) {
                    mul = mcm(mul, v[j]);
                }
            }
            ans += ((cant(i)&1)? 1 : -1) * (n/mul);
        }
        cout << "Case " << k << ": " << n-ans << '\n';
    }
    return 0;
}