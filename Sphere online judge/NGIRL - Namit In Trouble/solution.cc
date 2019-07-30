#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+1;
const int tam1 = 9592;
bool sieve[tam];
long long v[tam1];
int cant = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<long long, int> r, l;
    memset(sieve, -1, sizeof sieve);
    for(long long i = 2; i < tam; i++) {
        if( sieve[i] ) {
            v[cant++] = i*i;
            for(long long j = i*i; j < tam; j += i) {
                sieve[j] = false;
            }
        }
    }
    long long t, n, k;
    cin >> t;
    while( t-- ) {
        cin >> n >> k;
        int l1 = -1, r = tam1;
        while(r - l1 != 1) {
            int mid = (l1+r)>>1;
            if(v[mid] <= n) {
                l1 = mid;
            } else {
                r = mid;
            }
        }
        int l2 = -1; r = tam1;
        while(r - l2 != 1) {
            int mid = (l2+r)>>1;
            if(v[mid] <= k) {
                l2 = mid;
            } else {
                r = mid;
            }
        }
        int ans = l1-l2;
        cout << l1+1 << ' ' << max(ans, 0) << '\n';
    }
    return 0;
}