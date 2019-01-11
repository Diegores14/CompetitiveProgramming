#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, b, d;
    cin >> n >> b >> d;
    int temp, ans = 0;
    long long cont = 0;
    for(int i=0; i<n; i++) {
        cin >> temp;
        if(temp <= b) {
            cont += temp;
            if(cont > d) {
                ans++;
                cont = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}