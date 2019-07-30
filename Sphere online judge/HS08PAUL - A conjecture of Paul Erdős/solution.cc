#include <bits/stdc++.h>
using namespace std;
const int tam = 1e7+1;
bool sieve[tam];
bool used[tam];
int cant[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(long long i = 2; i*i < tam; i++) {
        if( sieve[i] ) {
            for(int j = i*i; j < tam; j += i) {
                sieve[j] = false;
            }
        }
    }
    memset(used, 0, sizeof used);
    for(long long x = 1; x*x < tam; x++ ) {
        for(long long y = 1; x*x + y*y*y*y < tam; y++) {
            long long a = x*x + y*y*y*y;
            if(sieve[a]) {
                used[a] = true;
            }
        }
    }
    memset(cant, 0, sizeof cant);
    for( int i = 2; i < tam; i++) {
        if(used[i]) {
            cant[i]++;
        }
        cant[i] += cant[i-1];
    }
    int t, n;
    cin >> t;
    while( t-- ) {
        cin >> n;
        cout << cant[n] << '\n';
    }
    return 0;
}