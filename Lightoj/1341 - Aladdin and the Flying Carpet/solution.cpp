#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int tam = 1e6+4, n = 78499;
bool sieve[tam];
int primes[n+10];
 
void sievefun( ) {
    int cnt = 0;
    memset(sieve, -1, sizeof sieve);
    for(LL i = 2; i < tam; i++) {
        if(sieve[i]) {
            primes[cnt++] = i;
            for(LL j = i*i; j < tam; j += i) {
                sieve[j] = false;
            }
        }
    }
}
 
LL Divisor(LL a) {
    LL ans = 1, cnt;
    for(int i=0; primes[i] <= a && i < n; i++) {
        if(a%primes[i] == 0) {
            cnt = 0;
            while(a%primes[i] == 0) {
                a /= primes[i];
                cnt++;
            }
            ans *= (cnt+1);
        }
    }
    if( a > 1) ans *= 2;
    return ans/2;
}
 
LL bs(LL a) {
    LL l = 1, r = 10000000;
    while(r - l != 1) {
        LL mid = (l + r)>>1;
        if(mid*mid <= a) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
 
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    LL a, b;
    sievefun();
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cin >> a >> b;
        cout << "Case " << r << ": ";
        if(bs(a) < b) {
            cout << "0\n";
        } else {
            int e=0;
            for(LL i = 1; i < b; i++) {
                if(a%i == 0) e++;
            }
            cout << Divisor(a) - e << '\n';
        }
    }
    return 0;
}