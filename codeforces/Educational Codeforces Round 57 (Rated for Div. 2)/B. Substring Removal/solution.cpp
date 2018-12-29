#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    long long ans = 1;
    long long cont = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = n-1; i>=0; i--){
        if(s[i] == s[n-1]){
            ans++;
            cont++;
        }else{
            break;
        }
    }
    cont++;
    for(int i=0; i<n; i++){
        if(s[i] != s[0])
            break;
        else{
            if(s[0] == s[n-1])
                ans = (ans%M + cont%M)%M;
            else{
                ans = (ans%M + 1)%M; 
            }
        }
    }
    cout << ans << '\n';
    return 0;
}