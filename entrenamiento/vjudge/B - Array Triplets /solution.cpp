#include <bits/stdc++.h>
using namespace std;
long long cant;
int n, temp2;
vector< int > v;

long long contador (int idx, const int i, int size, long long sum=0) {
    
    if (idx == n) {
        if (size == 0 || size == n - temp2) {
            return 0;
        }
        if (sum == cant) return 1;
        else return 0;
    }
    if ( (i>>idx)&1 ){
        return contador(idx+1, i, size, sum);
    } else {
        return contador(idx+1, i, size, sum) + contador(idx+1, i, size-1, sum + v[idx]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long total = 0;
    cin >> n;
    v.assign(n, 0);
    for(int &i : v){
        cin >> i;
        total += i;
    }
    cant = total / 3;
    int limit = 1<<n;
    if (total%3 == 0) {
        long long ans = 0;
        for (int i = 1; i < limit; i++) {
            long long temp = 0;
            temp2 = 0;
            for (int j=0; j<n; j++) {
                if ( i & (1<<j) ) {
                    temp += v[j];
                    temp2++;
                }
            }
            if (temp == cant) {
                ans += contador(0, i, n - temp2);
            }
        }
        cout << ans << '\n';
    } else {
        cout << "0\n";
    }
    return 0;
}