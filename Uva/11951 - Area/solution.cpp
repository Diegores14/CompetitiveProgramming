#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, k;
    cin >> t;
    for(int c = 1; c <= t; c++){
        cin >> n >> m >> k;
        long long area = 0, cost = k;
        vector< vector<long long> > v(n, vector<long long>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
                if(i > 0)
                    v[i][j] += v[i-1][j];
                if(j > 0)
                    v[i][j] += v[i][j-1];
                if(i > 0 && j > 0)
                    v[i][j] -= v[i-1][j-1];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int x=i; x<n; x++){
                    for(int y=j; y<m; y++){
                        long long temp = v[x][y];
                        if(i > 0)
                            temp -= v[i-1][y];
                        if(j > 0)
                            temp -= v[x][j-1];
                        if(i > 0 && j > 0)
                            temp += v[i-1][j-1];
                        if((x-i+1)*(y-j+1) >= area &&  temp <= k){
                            if((x-i+1)*(y-j+1) > area){
                                area = (x-i+1)*(y-j+1);
                                cost = temp;
                                continue;
                            }
                            if(temp < cost){
                                cost = temp;
                            }
                        }
                    }
                }
            }
        }
        cout << "Case #" << c << ": " << area << " " << cost << '\n';
    }
    return 0;
}