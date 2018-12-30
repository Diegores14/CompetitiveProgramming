#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = 0;
    for(int i=1; i<=a; i++){
        if(i+1 <= b && i+2 <= c){
            ans = i*3 + 3;
        }
    }
    cout << ans << '\n';
    return 0;
}