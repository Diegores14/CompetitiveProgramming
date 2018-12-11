#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin >> n;
    long long ans = 0;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        ans += temp * ((long long)i<<2);
    }
    cout << ans << '\n';
    return 0;
}