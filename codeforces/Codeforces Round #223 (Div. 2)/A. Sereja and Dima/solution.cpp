#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    int ans[2] = {0, 0};
    for(int &i: v) {
        cin >> i;
    }
    int i=0, j=n-1;
    for(int k=0; k<n; k++) {
        if(v[i] < v[j]) {
            ans[k%2] += v[j];
            j--;
        } else {
            ans[k%2] += v[i];
            i++;
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}