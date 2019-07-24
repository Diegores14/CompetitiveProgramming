#include <bits/stdc++.h>
using namespace std;
const int tam = 3001;
bool criba[tam];
int prime[tam];
int len = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(criba, -1, sizeof criba);
    memset(prime, 0, sizeof prime);
    criba[0] = criba[1] = false;
    for(long long i = 2; i < tam; i++) {
        if(criba[i]) {
            for(long long j = 2*i; j < tam; j += i) {
                criba[j] = false;
                prime[j]++;
            }
        }
    }
    vector<long long> ans;
    for(int i = 30; i < tam; i++) {
        if(prime[i] >= 3) {
            ans.emplace_back(i);
        }
    }
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << ans[n-1] << '\n';
    }
    return 0;
}