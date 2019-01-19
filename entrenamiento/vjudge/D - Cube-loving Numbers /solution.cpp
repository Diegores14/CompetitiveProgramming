#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
vector<int> p(78498);
long long t, n;

long long solution(int idx, long long curr, int paridad) {
    if(idx == 78498) {
        return 0;
    }
    long long temp = 1LL * p[idx] * p[idx] * p[idx];
    if(temp > n/curr) {
        return 0;
    }
    long long ans = (paridad? -1LL : 1LL) * (n/curr/temp);
    ans += solution(idx+1, curr, paridad);
    ans += solution(idx+1, curr*temp, paridad^1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cont = 0;
    vector<bool> criba(1000001, true);
    int k=0;
    criba[0]=criba[1]=false;
    for(long long i=2; i<=1000000; i++) {
        if(criba[i]) {
            p[k++] = i;
            for(long long j = i*i; j<=1000000; j+=i) {
                criba[j]=false;
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << solution(0, 1, 0) << '\n';
    }
    return 0;
}