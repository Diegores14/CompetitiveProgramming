#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    int m, a, b;
    cin >> m;
    for(int i = 0; i<m; i++) {
        cin >> a >> b;
        a--;
        if(0<a) {
            if(v[a] < b) {
                v[a-1] += v[a];
            } else {
                v[a-1] += b-1;
            }
        }
        if(a < n-1) {
            if(v[a]-b > 0) {
                v[a+1] += v[a]-b;
            }
        }
        v[a] = 0;
    }
    for(int i: v) {
        cout << i << '\n';
    }
    return 0;
}