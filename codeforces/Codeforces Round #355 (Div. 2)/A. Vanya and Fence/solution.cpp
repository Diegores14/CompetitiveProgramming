#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, h, temp;
    cin >> n >> h;
    long long ans = 0;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(temp > h)
            ans++;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}