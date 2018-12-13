#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q;
    while(cin >> n >> m, n || m){
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int i=0; i<n; i++){
                int a=-1, b=m;
                while(b-a != 1){
                    int mid = (a+b)>>1;
                    if(l <= v[i][mid]){
                        b = mid;
                    }else{
                        a = mid;
                    }
                }
                for(int j = ans; j+b < m && i+j < n && v[i+j][j+b] <= r; j++){
                    ans++;
                }
            }
            cout << ans << '\n';
        }
        cout << "-\n";
    }
    return 0;
}