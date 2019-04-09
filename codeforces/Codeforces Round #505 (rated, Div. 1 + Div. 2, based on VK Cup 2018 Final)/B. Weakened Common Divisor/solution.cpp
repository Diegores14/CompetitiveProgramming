#include <bits/stdc++.h>
using namespace std;
const int tam = 100000;
int cant = 0;
bool criba[tam];
int primes[tam];

long long gcd(long long a, long long b) {
    return (b? gcd(b, a%b) : a);
}

void getFactors(set<int> & factors, int value) {
    for(int i = 0; primes[i]*primes[i] <= value; i++) {
        if(value%primes[i] == 0){
            factors.insert(primes[i]);
            while(value%primes[i] == 0){
                value /= primes[i];
            }
        }
    }
    if(value > 1) {
        factors.insert(value);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(criba, 1, sizeof criba);
    primes[cant++] = 2;
    for(long long i=3; i < tam; i += 2) {
        if(criba[i]){
            primes[cant++] = i;
            for(long long j = 0; j < tam; j += (i<<1)) {
                criba[j] = 0;
            }
        }
    }
    int n;
    cin >> n;
    vector< pair<int, int> > v(n);
    for(auto &i: v) {
        cin >> i.first >> i.second;                
    }
    set<int> factors;
    getFactors(factors, v[0].first);
    getFactors(factors, v[0].second);
    for(auto &i: factors) {
        bool flag = true;
        for(int j=0; j<n; j++) {
            if(v[j].first%i && v[j].second%i) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}