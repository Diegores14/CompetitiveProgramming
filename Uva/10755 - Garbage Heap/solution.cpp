#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b, c;
    long long v[20][20][20];
    cin >> t;
    while(t--){
        long long ans = -1e17;
        cin >> a >> b >> c;
        for(int k=0; k<a; k++){
            for(int i = 0; i<b; i++){
                for(int j=0; j<c; j++){
                    cin >> v[k][i][j];
                    if(i>0)
                        v[k][i][j] += v[k][i-1][j];
                    if(j>0)
                        v[k][i][j] += v[k][i][j-1];
                    if(k>0)
                        v[k][i][j] += v[k-1][i][j];
                    if(i>0 && j>0)
                        v[k][i][j] -= v[k][i-1][j-1];
                    if(k>0 && j>0)
                        v[k][i][j] -= v[k-1][i][j-1];
                    if(k>0 && i>0)
                        v[k][i][j] -= v[k-1][i-1][j];
                    if(k > 0 && j > 0 && i > 0)
                        v[k][i][j] += v[k-1][i-1][j-1];
                }
            }
        }
        for(int k=0; k<a; k++){
            for(int i=0; i<b; i++){
                for(int j=0; j<c; j++){
                    for(int z = k; z<a; z++){
                        for(int x=i; x<b; x++){
                            for(int y=j; y<c; y++){
                                long long temp = v[z][x][y];
                                if(i>0)
                                    temp -= v[z][i-1][y];
                                if(j>0)
                                    temp -= v[z][x][j-1];
                                if(k>0)
                                    temp -= v[k-1][x][y];
                                if(i>0 && j>0)
                                    temp += v[z][i-1][j-1];
                                if(k>0 && j>0)
                                    temp += v[k-1][x][j-1];
                                if(k>0 && i>0)
                                    temp += v[k-1][i-1][y];
                                if(k > 0 && j > 0 && i > 0)
                                    temp -= v[k-1][i-1][j-1];
                                ans = max(ans, temp);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        if(t)
            cout << '\n';
    }
    return 0;
}