#include <bits/stdc++.h>
using namespace std;
const int Tam = 15000005;
int sieve[Tam];
int ans[Tam];

int GCD(int a, int b) {
    return b? GCD(b, a%b) : a;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, G = 0, x;
    memset(ans, 0, sizeof ans);
    memset(sieve, 0, sizeof sieve);
    for(long long i=2; i < Tam; i++) {
        if(!sieve[i]) {
            for(long long j=i; j<Tam; j+=i) {
                sieve[j] = i;
            }
        }
    }
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        G = GCD(G, v[i]);
    }
    for(int i = 0; i < n; i++) {
        int temp = v[i]/G;
        while(temp != 1) {
            ans[x = sieve[temp]]++;
            while(sieve[temp] == x) {
                temp /= sieve[temp];
            }
        }
    }
    int mmin = n;
    for(int i=0; i<Tam; i++) {
        mmin = min(mmin, n - ans[i]);
    }
    if(mmin != n)
        cout << mmin << '\n';
    else
        cout << -1 << '\n';
    return 0;
}