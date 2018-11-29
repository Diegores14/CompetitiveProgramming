#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<long double> v(6);
    long double total = 0, ans = 100000000;
    for(int i=0; i<6; i++){
        cin >> v[i];
        total += v[i]*(i+1);
    }
    for(int i=0; i<6; i++){
        ans = min(ans, abs((i+1) - (3.5-(total-(v[i]*(i+1))))/v[i]));
    }
    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}