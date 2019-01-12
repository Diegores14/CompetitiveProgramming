#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char c;
    int x, y, tempx=0, tempy=0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> c >> x >> y;
        //cout << c << ' ' << x << ' ' << y << '\n';
        if(c == '+'){
            tempx = max(tempx, max(x, y));
            tempy = max(tempy, min(x, y));
        } else {
            if((tempx <= x && tempy <= y) || (tempy <= x && tempx <= y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;

}