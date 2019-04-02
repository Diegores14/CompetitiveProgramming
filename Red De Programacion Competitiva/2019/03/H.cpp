#include <bits/stdc++.h>
using namespace std;
int tam = 1000005;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    vector<bool> sieve(tam, true);
    sieve[0] = sieve[1] = false;
    int primes[78499], k = 0;
    for(long long i=2; i*i < tam; i++){
        if(sieve[i]) {
            for(long long j = i*i; j < tam; j +=i)
                sieve[j] = false;
        }
    }
    for(int i=0; i < tam; i++) {
        if(sieve[i]) {
            primes[k++] = i;
        }
    }
    int ans = 0, x;
    cin >> x;
    while(x >= 4) {
        ans++;
        for(int i=0; i < 78499; i++) {
            if(sieve[x - primes[i]]) {
                x -= 2 * primes[i];
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}