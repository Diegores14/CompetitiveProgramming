#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return (a==0)? b : gcd(b%a, a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, a;
    set<int> se;
    for(int i=2; i<=26; i++) {
        se.insert((1<<i)-1);
    }
    cin >> q;
    while(q--){
        cin >> a;
        if(se.count(a)) {
            int ans = 1;
            for(int i=2; i*i<=a; i++) {
                if(a%i == 0) {
                    ans = a/i;
                    break;
                }
            }
            cout << ans << '\n';
        } else {
            int ans = 0;
            while(a) {
                ans <<= 1;
                ans ^= 1;
                a >>= 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}