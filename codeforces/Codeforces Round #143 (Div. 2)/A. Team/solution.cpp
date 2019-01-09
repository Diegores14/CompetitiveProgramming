#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    long long ans = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        int temp2 = 0;
        for(int j=0; j<3; j++) {
            cin >> temp;
            if (temp) {
                temp2++;
            }
        }
        if(temp2>1){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}