#include <bits/stdc++.h>
using namespace std;
const int tam = 5*1000000+1;
int ans[tam];
unsigned long long prefixsum[tam];

void sievefun() {
    for(int i=0; i<tam; i++) {
        ans[i] = i;
    }
    for(long long i = 2; i < tam; i++) {
        if(ans[i] == i) {
            for(long long j = i; j < tam; j += i) {
                ans[j] = ans[j] - ans[j]/i;
            }
        }
    }
    prefixsum[0] = 0;
    for(int i=1; i < tam; i++ ) {
        prefixsum[i] = 1ULL*ans[i]*ans[i] + prefixsum[i-1];
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=0, a , b;
    sievefun();
    cin >> t;
    for( int r = 1; r <= t; r++)  {
        cin >> a >> b;
        cout << "Case " << r << ": " << prefixsum[b] - prefixsum[a-1] << '\n';
    }
    return 0;
}