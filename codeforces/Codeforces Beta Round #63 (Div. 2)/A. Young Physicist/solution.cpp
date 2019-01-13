#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x=0, y=0, z=0;
    int tempx, tempy, tempz;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> tempx >> tempy >> tempz;
        x += tempx;
        y += tempy;
        z += tempz;
    }
    if(x || y || z) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}