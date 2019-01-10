#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ans = 0, temp, policesOfficers = 0, n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> temp;
        policesOfficers += temp;
        if(policesOfficers < 0) {
            ans -= policesOfficers;
            policesOfficers = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}