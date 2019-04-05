#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int primes[1000000];
bool criba[10000005];
int n = 0;

long long solve(long long val, int idx, int paridad) {
    long long ans = paridad * (b/val - (a-1)/val) * (d/val - (c-1)/val);
    for(int i = idx; i<n; i++) {
        if(val * primes[i] <= min(b, d)) {
            ans += solve(val * primes[i], i+1, paridad * -1);
        } else {
            break;
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    primes[n++] = 2;
    memset(criba, 1, sizeof criba);
    for(long long i = 3; i <= 10000000; i += 2) {
        if(criba[i]){
            primes[n++] = i;
            for(long long j = i*i; j <= 10000000; j += 2*i) {
                criba[j] = false;
            }
        }
    }
    cin >> a >> b >> c >> d;
    cout << solve(1, 0, 1) << '\n';
    return 0;
}