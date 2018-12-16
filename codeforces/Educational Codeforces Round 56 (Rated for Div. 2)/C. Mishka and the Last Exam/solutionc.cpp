#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    long long temp, mmin=0;
    cin >> n;
    int limit = (n>>1);
    vector<long long > a(n+2), b(limit);
    a[0] = 0;
    a[n+1] = 1e18;
    for(int i=1; i<=limit; i++){
        cin >> temp;
        if(temp-mmin > a[n-i+2]){
            mmin = temp - a[n-i+2];
        }
        a[n-i+1] = temp - mmin;
        a[i] = mmin;
    }
    for(int i=1; i<=n; i++){
        cout << a[i] << ((i==n)? '\n': ' ');
    }
    return 0;
}