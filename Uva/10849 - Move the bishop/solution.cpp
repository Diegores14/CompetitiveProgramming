#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y, int x1, int y1, int varx, int vary, int n){
    int _x = x;
    int _y = y;
    if(x-y == x1-y1 || x+y == x1+y1)
        return 1;
    while(true){
        _x += varx;
        _y += vary; 
        if(_x < 0 || _y < 0 || _x >= n || _y >= n)
            return -1;
        if(_x - _y == x1 - y1 || _x + _y == x1 + y1)
            return 2;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, c, n, x, y, x1, y1;
    cin >> t; 
    while(t--){
        cin >> c >> n;
        while(c--){
            cin >> y >> x >> y1 >> x1;
            if(x == x1 && y == y1)
                cout << "0\n";
            else{
                int aux = solve(x, y, x1, y1, 1, 1, n);
                if(aux != -1){
                    cout << aux << '\n';
                    continue;
                }
                aux = solve(x, y, x1, y1, -1, 1, n);
                if(aux != -1){
                    cout << aux << '\n';
                    continue;
                }
                aux = solve(x, y, x1, y1, -1, -1, n);
                if(aux != -1){
                    cout << aux << '\n';
                    continue;
                }
                aux = solve(x, y, x1, y1, 1, -1, n);
                if(aux != -1){
                    cout << aux << '\n';
                    continue;
                }
                cout << "no move\n";
            }
        }
    }
    return 0;
}