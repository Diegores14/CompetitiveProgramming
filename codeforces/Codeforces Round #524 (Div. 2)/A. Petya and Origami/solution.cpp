#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    ans += ceil((double(n)*2)/k);
    ans += ceil((double(n)*5)/k);
    ans += ceil((double(n)*8)/k);
    cout << ans << '\n';
    return 0;
}