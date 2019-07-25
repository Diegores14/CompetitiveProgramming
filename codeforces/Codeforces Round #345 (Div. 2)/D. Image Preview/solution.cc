#include <bits/stdc++.h>
using namespace std;
const int tam = 5e5+5;
long long sum[tam], sum1[tam];
int n, a, b, t;



int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> a >> b >> t;
    string s;
    cin >> s;
    sum[0] = (s[0] == 'w')*b + 1;
    for(int i = 1; i < n; i++) {
        sum[i] = (s[i] == 'w')*b + a + sum[i-1] + 1;
    }
    sum1[n-1] = (s[n-1] == 'w')*b + 1;
    for(int i = n-2; i >= 0; i--) {
        sum1[i] = (s[i] == 'w')*b + a + sum1[i+1] + 1;
    }
    int ans = 0; 
    for(int i = 0; i < n; i++) {
        if(sum[i] > t) break;
        int l = i, r = n; 
        while(r-l != 1) {
            int mid = (l+r)>>1;
            long long suma = sum[i] + sum1[mid] + a*(i+1);
            if(suma <= t) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans = max(ans, i+1 + n-r);
    }
    string ss = s;
    for(int i = 1; i < n; i++) {
        ss[i] = s[n-i];
    }
    s = ss;
    sum[0] = (s[0] == 'w')*b + 1;
    for(int i = 1; i < n; i++) {
        sum[i] = (s[i] == 'w')*b + a + sum[i-1] + 1;
    }
    sum1[n-1] = (s[n-1] == 'w')*b + 1;
    for(int i = n-2; i >= 0; i--) {
        sum1[i] = (s[i] == 'w')*b + a + sum1[i+1] + 1;
    }
    for(int i = 0; i < n; i++) {
        if(sum[i] > t) break;
        int l = i, r = n; 
        while(r-l != 1) {
            int mid = (l+r)>>1;
            long long suma = sum[i] + sum1[mid] + a*(i+1);
            if(suma <= t) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans = max(ans, i+1 + n-r);
    }
    cout << ans << '\n';
    return 0;
}