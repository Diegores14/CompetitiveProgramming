#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;

long long bs1(long long n) {
    long long l = 0, r = 2000000005;
    while(r-l != 1) {
        long long mid = (l+r)>>1;
        if(mid * mid <= n) l = mid;
        else r = mid;
    }
    return l;
}

long long bs2(long long n) {
    long long l = 0, r = 2000005;
    while(r-l != 1) {
        long long mid = (l+r)>>1;
        if(mid * mid * mid <= n) l = mid;
        else r = mid;
    }
    return l;
}

long long GCD(long long a, long long b) {
    return b? GCD(b, a%b) : a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long a[n];
    long long ans = 1;
    map<long long, int> m, aux;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        long long x = bs1(a[i]);
        long long y = bs2(a[i]);
        if(x * x == a[i]) {
            long long temp = bs1(x);
            if(temp * temp == x) m[temp] +=4;
            else m[x] += 2;
        } else {
            if(y * y * y == a[i]) m[y] += 3;
            else {
                bool flag = true;
                for(int j=0; j<n; j++) {
                    long long d = GCD(a[i], a[j]);
                    if(1 < d && d < a[i]) {
                        m[d]++;
                        m[a[i]/d]++;
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    aux[a[i]]++;
                }
            }
        }
    }
    for(auto &i: m) {
        ans = (ans * (i.second + 1)) % mod;
    }
    for(auto &i: aux) {
        ans = (ans * (i.second + 1)) % mod;
        ans = (ans * (i.second + 1)) % mod;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}