#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p, k;
    cin >> n >> p >> k;
    int i = max(1,p-k);
    if(i != 1) {
        cout << "<< ";
    }
    while(i<p) {
        cout << i++ << ' ';
    }
    cout << "(" << i++ << ')';
    while(k-- && i<=n) {
        cout << ' ' << i++;
    }
    if(i <= n) {
        cout << " >>";
    }
    cout << '\n';
    return 0;
}