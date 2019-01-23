#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(i<n-2 && s[i] == 'B' && s[i+1] == 'B' && s[i+2] == 'B') {
            s[i+1] = 'G';
            ans++;
            continue;
        }
        if(i<n-2 && s[i] == 'G' && s[i+1] == 'G' && s[i+2] == 'G') {
            s[i+1] = 'B';
            ans++;
            continue;
        }
        if(i<n-2 && s[i] == 'R' && s[i+1] == 'R' && s[i+2] == 'R') {
            s[i+1] = 'G';
            ans++;
            continue;
        }
        if(i < n-1 && s[i] == 'B' && s[i+1] == 'B') {
           if(i+2 == n) {
               s[i+1] = 'R';
           } else {
               if(s[i+2] == 'R') {
                   s[i+1] = 'G';
               } else {
                   s[i+1] = 'R';
               }
           }
           ans++;
           continue;
        }
        if(i < n-1 && s[i] == 'R' && s[i+1] == 'R') {
           if(i+2 == n) {
               s[i+1] = 'G';
           } else {
               if(s[i+2] == 'G') {
                   s[i+1] = 'B';
               } else {
                   s[i+1] = 'G';
               }
           }
           ans++;
           continue;
        }
        if(i < n-1 && s[i] == 'G' && s[i+1] == 'G') {
           if(i+2 == n) {
               s[i+1] = 'B';
           } else {
               if(s[i+2] == 'B') {
                   s[i+1] = 'R';
               } else {
                   s[i+1] = 'B';
               }
           }
           ans++;
           continue;
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
    return 0;
}