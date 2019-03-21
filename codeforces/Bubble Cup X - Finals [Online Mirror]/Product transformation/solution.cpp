#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

long long fact[1000005];
long long fact_1[1000005];

LL extendedEuclidean(LL a, LL b, LL & x, LL & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = extendedEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

LL inverse(LL a, LL m) {
    LL x, y;
    LL g = extendedEuclidean(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

void cal(int r) {
    fact[1] = fact[0] = 1;
    fact_1[1] = fact_1[0] = inverse(1, r);
    for(long long i = 2; i<=1000000; i++) {
        fact[i] = (i * fact[i-1]) % r;
        long long temp = inverse(i, r);
        fact_1[i] = (temp * fact_1[i-1]) % r;
    }
}

int calP( int a, int Q) {
    long long x = (a)%Q;
    int i = 1;
    for(; x != 1; i++) {
        x = (x*a) % Q;
    }
    return i;
}

int combinatoric(int n, int k, int mod) {
    if(n-k < 0) {
        return 0;
    }
    return (((fact[n] * fact_1[k]) % mod )* fact_1[n-k]) % mod; 
}

long long exponentation(long long a, long long n, long long r) {
    long long ans = 1;
    long long po = a;
    while(n) {
        if(n&1) {
            ans = (ans * po) % r;
        }
        po = (po * po) % r;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a, q;
    cin >> n >> m >> a >> q;
    int p = calP(a, q);
    cal(p);
    int ans[n+1];
    ans[0] = 0;
    for(int i=1; i <= n; i++) {
        ans[i] = (combinatoric(m, i-1, p) + ans[i-1]) % p;
    }
    reverse(ans, ans+n+1);
    for(int i=0; i<n; i++) {
        cout << exponentation(a, ans[i], q) << (i==n-1? '\n' : ' ');
    }
}