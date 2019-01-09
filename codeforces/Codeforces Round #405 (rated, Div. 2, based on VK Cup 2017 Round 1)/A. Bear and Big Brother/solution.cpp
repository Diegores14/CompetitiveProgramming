#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    while(a <= b){
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}