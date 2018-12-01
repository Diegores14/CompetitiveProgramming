#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int limit = (1<<(n)), aux;
        int ans = 0;
        map<int, int> corners;
        for(int i=0; i<limit; i++){
            cin >> aux;
            corners[i] = aux;
        }
        vector<int> v(limit, 0);
        for(int i=0; i<limit; i++){
            for(int j=0; j<n; j++){
                v[i] += corners[i^(1<<j)];
            }
        }
        for(int i=0; i<limit; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, v[i] + v[i^(1<<j)]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}