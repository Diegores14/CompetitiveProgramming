#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    char temp = 'a';
    cin >> s;
    long long ans = 0;
    for(char &i: s){
        if(i<temp) {
            ans += min(temp-i, (i+26-temp));
        } else {
            ans += min(abs(i-temp), abs(i-(temp+26)));
        }
        temp = i;
    }
    cout << ans << '\n';
    return 0;
}