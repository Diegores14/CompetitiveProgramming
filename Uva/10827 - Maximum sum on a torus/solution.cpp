#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int limit = n<<1, ans = -100;
        vector< vector<int> > v(limit, vector<int>(limit, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> v[i][j];
                v[i][j+n] = v[i][j];
                v[i+n][j] = v[i][j];
                v[i+n][j+n] = v[i][j];
            }
        }
        for(int i=0; i<limit; i++){
            for(int j=0; j<limit; j++){
                if(i > 0)
                    v[i][j] += v[i-1][j];
                if(j > 0)
                    v[i][j] += v[i][j-1];
                if(i > 0 && j > 0)
                    v[i][j] -= v[i-1][j-1];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int x = i; x < i+n; x++){
                    for(int y = j; y < j+n; y++){
                        int temp = v[x][y];
                        if(i > 0)
                            temp -= v[i-1][y];
                        if(j > 0)
                            temp -= v[x][j-1];
                        if(i > 0 && j > 0)
                            temp += v[i-1][j-1];
                        ans = max(ans, temp);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}