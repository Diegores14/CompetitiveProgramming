#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, y;
    int tempx, tempy;
    cin >> n >> x >> y;
    set<long double> se;
    for(int i=0; i<n; i++) {
        cin >> tempx >> tempy;
        if((tempx-x))
            se.insert((long double)(tempy-y) / (tempx-x));
        else 
            se.insert(1e18);
    }
    cout << se.size() << '\n';
    return 0;
}