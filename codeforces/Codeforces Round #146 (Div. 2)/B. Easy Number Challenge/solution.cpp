#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
long long mod = 1<<30;

void solution(int n) {
    for(int i = 2; i*i <= n; i++) {
        while(n%i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if(n > 1) {
        m[n]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long ans = 0;
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            for(int k=1; k<=c; k++) {
                m.clear();
                solution(i);
                solution(j);
                solution(k);
                long long temp = 1;
                for(auto &i: m) {
                    temp *= (i.second+1);
                }
                ans = (ans + temp%mod)%mod;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}