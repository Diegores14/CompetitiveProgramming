#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6 + 5;
bool sieve[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = false;
    for(long long i = 2; i*i < tam; i++) {
        if(sieve[i] == true) {
            for(long long j = i*i; j < tam; j += i) {
                sieve[j] = false;
            }
        } 
    }
    long long n, temp;
    cin >> n;
    while(n--) {
        cin >> temp;
        long long l = 1, r = 1e7;
        while(r-l != 1) {
            long long mid = (l+r)>>1;
            if(mid*mid <= temp) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if(l*l == temp && sieve[l])
            cout << "YES" << '\n';
        else {
            cout << "NO\n";
        }
    }
    return 0;
}