#include <bits/stdc++.h>
using namespace std;
const int limit = 5000000;
const int tam = 100000001;
int primes[limit];
bool criba[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l=0;
    primes[l++] = 2;
    memset(criba, 1, sizeof criba);
    for(long long i=3; l < limit; i += 2) {
        if(criba[i]){
            primes[l++] = i;
            for(long long j=i*i; j <= 100000000; j += (i<<1)) {
                criba[j] = false;
            }
        }
    }
    int q, n;
    cin >> q;
    while(q--) {
        cin >> n;
        cout << primes[n-1] << '\n';
    }
    return 0;
}