#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, d, k;
    cin >> t;
    while(t--){
        int i;
        cin >> i;
        vector<int> v(i+1);
        for(int j=i; j>=0; j--){
            cin >> v[j];
        }
        cin >> d >> k;
        int r = 1;
        for(int j = d*r; j<k; r++, j += r*d){
            
        }
        long long ans = 0;
        for(int j: v){
            ans = ans * r + j;
        }
        cout << ans << '\n';
    }
    return 0;
}