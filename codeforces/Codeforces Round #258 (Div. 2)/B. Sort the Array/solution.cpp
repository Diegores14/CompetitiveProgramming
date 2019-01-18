#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int cont = 0;
    cin >> n;
    int v[n];
    for(int &i: v) {
        cin >> i;
    }
    vector<int> temp(v, v+n);
    sort(temp.begin(), temp.end());
    int l = n, r = 0;
    for(int i=0; i<n; i++) {
        if(v[i] != temp[i]) {
            l = min(i, l);
            r = i;
            cont++;
        }
    }
    if(cont) {
        reverse(v+l, v+r+1);
        cont = 0;
        for(int i=0; i<n; i++) {
            if(v[i] != temp[i]) {
                cont++;
            }
        }
        if(cont == 0) {
            cout << "yes\n" << l+1 << ' ' << r+1 << '\n';
        } else {
            cout << "no\n";
        }
    } else {
        cout << "yes\n1 1\n";
    }
    return 0;
}