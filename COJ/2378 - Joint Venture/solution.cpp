#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, n; 
    while(cin >> x) {
        x *= 10000000;
        cin >> n;
        int v[n];
        for(int &i: v) {
            cin >> i;
        }
        sort(v, v+n);
        int i=0, j = n-1;
        int ansx = -1, ansy = -1;
        while(i < j) {
            if(v[i] + v[j] == x) {
                ansx = i;
                ansy = j;
                break;
            }
            if(v[i] + v[j] <= x) {
                i++;
            } else {
                j--;
            }
        }
        if(ansx != -1) {
            cout << "yes " << v[ansx] << ' ' << v[ansy] << '\n';
        } else {
            cout << "danger" << '\n';
        }
    }
    return 0;
}