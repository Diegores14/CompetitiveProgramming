#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k = 1, n, m, temp;
    while(cin >> n, n){
        cout << "Case " << k++ << ":\n";
        vector<int> v(n);
        for(int & i : v){
            cin >> i;
        }
        long long mmin, ans = 100000000000000;
        cin >> m;
        while(m--){
            cin >> temp;
            mmin = 100000000000;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(abs(v[i]+v[j] - temp) < mmin){
                        mmin = abs(v[i] + v[j] - temp);
                        ans = v[i] + v[j];
                    }
                }
            }
            cout << "Closest sum to " << temp << " is " << ans << ".\n";
        }
    }
    return 0;
}