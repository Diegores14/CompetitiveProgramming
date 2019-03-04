#include <bits/stdc++.h>
using namespace std;
long long Mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    long long temp = 0, curr = 0, ans = 0; 
    vector<long long> v(s.size());
    for( int i=s.size()-1; i>=0; i--) {
        if(s[i] == 'a') {
            v[i] = (curr + 1)%Mod;
            temp = (temp + v[i])%Mod;
        }
        if(s[i] == 'b') {
            curr = temp;
        }
    }
    for(long long &i: v) {
        ans = ( ans + i )%Mod;
    }
    cout << ans << '\n';
    return 0;
}