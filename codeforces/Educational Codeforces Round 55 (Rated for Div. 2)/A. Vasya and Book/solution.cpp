#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long d){
    if(abs(a-b)%d)
        return 4e10;
    else
        return abs(a-b)/d;
}

long long solve2(long long a, long long b, long long d){
    return abs(a-b)/d + (abs(a-b)%d > 0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t, n, x, y, d;
    cin >> t;
    while(t--){
        cin >> n >> x >> y >> d;
        long long ans = 2e10;
        ans = min(ans, solve(x,y,d));
        ans = min(ans, solve2(x,1,d) + solve(y, 1, d)) ;
        ans = min(ans, solve2(x,n,d) + solve(y, n, d));
        if(ans >= 2e10)
            cout << "-1\n";
        else
            cout << ans << '\n';
    }
    return 0;
}