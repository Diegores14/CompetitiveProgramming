#include <bits/stdc++.h>
using namespace std;

void Fill(int x, int y, int n, vector< vector<int> > & v){
    if(x < 0 || y < 0 || x >= n || y >= n || v[y][x] == -1)
        return;
    v[y][x]++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t, k=0;
    cin >> t;
    while(t--){
        if(k)
            cout << '\n';
        k++;
        cin >> n;
        string s;
        vector< vector<int> > v(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<n; j++){
                if(s[j] == '*'){
                    v[i][j] = -1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][j] == -1){
                    Fill(j, i+1, n, v);
                    Fill(j+1, i, n, v);
                    Fill(j, i-1, n, v);
                    Fill(j-1, i, n, v);
                    Fill(j+1, i+1, n, v);
                    Fill(j+1, i-1, n, v);
                    Fill(j-1, i+1, n, v);
                    Fill(j-1, i-1, n, v);            
                }
            }
        }
        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<n; j++){
                if(s[j] == 'x'){
                    if(v[i][j] == -1)
                        cout << '*';
                    else
                        cout << v[i][j];
                }else
                    cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}