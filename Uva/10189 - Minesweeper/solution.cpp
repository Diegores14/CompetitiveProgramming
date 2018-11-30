#include <bits/stdc++.h>
using namespace std;

void fill(int x, int y, int n, int m, vector< vector<int> > & v){
    if(x < 0 || y < 0 || x >= m || y >= n || v[y][x] == -1){
        return;
    }
    v[y][x]++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k=0;
    while(cin >> n >> m, n && m){
        if(k)
            cout << '\n';
        vector< vector<int> > v(n, vector<int>(m, 0));
        char aux;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> aux;
                if(aux == '*')
                    v[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == -1){
                    fill(j+1, i, n, m, v);
                    fill(j+1, i+1, n, m, v);
                    fill(j+1, i-1, n, m, v);
                    fill(j-1, i, n, m, v);
                    fill(j-1, i+1, n, m, v);
                    fill(j-1, i-1, n, m, v);
                    fill(j, i+1, n, m, v);
                    fill(j, i-1, n, m, v);
                }
            }
        }
        cout << "Field #" << ++k << ":\n";
        for(int i=0; i<n; i++){
            for(int j=0; j < m; j++){
                if(v[i][j] == -1)
                    cout << "*";
                else
                    cout << v[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}