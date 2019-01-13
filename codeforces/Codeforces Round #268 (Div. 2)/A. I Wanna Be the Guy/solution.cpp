#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p, temp, ans = 1;
    cin >> n;
    vector<int> v(n+1, 0);
    cin >> p;
    for(int i=0; i<p; i++) {
        cin >> temp;
        v[temp] = 1;
    }
    cin >> p;
    for(int i=0; i<p; i++) {
        cin >> temp;
        v[temp] = 1;
    }
    for(int i=1; i<=n; i++) {
        ans = (ans&v[i]);
    }
    if(ans) {
        cout << "I become the guy.\n";
    } else {
        cout << "Oh, my keyboard!\n";
    }
    return 0;
}