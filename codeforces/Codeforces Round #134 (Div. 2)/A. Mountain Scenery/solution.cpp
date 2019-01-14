#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    n = (n<<1) + 1;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    int i = 1;
    while(k) {
        if(v[i-1] + 1 < v[i] && v[i+1] + 1 < v[i]) {
            v[i]--;
            k--;
        }
        i += 2;
    }
    for(int i=0; i<n; i++) {
        cout << v[i] << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}