#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int cont=0, temp;
    vector<int> v(n, 0);
    for(int i=0; i<m; i++) {
        cin >> temp;
        v[--temp]++;
        if(v[temp] == 1) {
            cont++;
        }
        if(cont == n) {
            for(int i=0; i<n; i++) {
                v[i]--;
                if(v[i] == 0) {
                    cont--;
                }
            }
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << '\n';
    return 0;
}