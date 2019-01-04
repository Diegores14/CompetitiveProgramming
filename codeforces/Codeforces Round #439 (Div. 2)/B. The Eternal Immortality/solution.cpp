#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long ans = 1;
    a++;
    while(a <= b && ans != 0){
         ans = (ans * a%10)%10;
         a++;
    }
    cout << ans << '\n';
    return 0;
}