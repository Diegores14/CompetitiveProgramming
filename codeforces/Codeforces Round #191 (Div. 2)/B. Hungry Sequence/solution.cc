#include <bits/stdc++.h>
using namespace std;
const int tam = 1e7+1;
bool sieve[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = false;
    for(long long i = 2; i*i < tam; i++) {
        if(sieve[i]) {
            for(int j = i*i; j < tam; j += i) {
                sieve[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < tam && n; i++) {
        if(sieve[i]) {
            n--;
            cout << i << (n? ' ' : '\n');
        }
    }
    return 0;
}