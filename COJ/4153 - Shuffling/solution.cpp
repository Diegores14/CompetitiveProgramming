#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    n = (1<<n);
    int v[n];
    for(int &i: v) {
        cin >> i;
    }
    if(t&1) {
        for(long long i=1; i < n; i <<= 1) {
            for(long long j=0; j < n; j++ ) {                
                swap(v[j], v[j+i]);
                if( (j+1)%i == 0) {
                    j += i;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << v[i] << (i == n-1? '\n' : ' ');
    }
    return 0;
}