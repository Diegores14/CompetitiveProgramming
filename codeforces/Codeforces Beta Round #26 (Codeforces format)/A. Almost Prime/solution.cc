#include <bits/stdc++.h>
using namespace std;
bool sieve[3001];
int primes[22384];
int len = 0;

void precomputo() {
    memset( sieve, -1, sizeof sieve );
    for( int i = 2; i <= 3000; i++ ) {
        if( sieve[i] ) {
            primes[len++] = i;
            for( int j = i*i; j <= 3000; j += i )  {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomputo();
    int n, ans = 0;
    cin >> n;
    for( int i = 0; i <= n; i++ ) {
        int temp = i, cnt = 0;
        for( int j = 0; j < len && primes[j] <= temp; j++ ) {
            if( i%primes[j] == 0 ) cnt++;
        }
        ans += (cnt == 2);
    }
    cout << ans << '\n';
    return 0;
}