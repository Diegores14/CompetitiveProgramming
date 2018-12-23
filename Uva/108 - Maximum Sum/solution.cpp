#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int ans = -127*100*100;
    cin >> n;
    vector< vector<int> > v(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
            if(j > 0)
                v[i][j] += v[i][j-1];
            if(i > 0)
                v[i][j] += v[i-1][j];
            if(j > 0 && i > 0)
                v[i][j] -= v[i-1][j-1];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int x = i; x < n; x++){
                for(int y = j; y < n; y++){
                    int temp = v[x][y];
                    if(i>0)
                        temp -= v[i-1][y];
                    if(j>0)
                        temp -= v[x][j-1];
                    if(i>0 && j>0)
                        temp += v[i-1][j-1];
                    ans = max(ans, temp);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}