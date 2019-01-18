#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<char> v({'R', 'O', 'Y', 'G', 'B', 'I', 'V'});
    for(char &i: v) {
        cout << i;
    }
    int j=3;
    for(int i = 7; i<n; i++) {
        cout << v[j++];
        if(j==7) {
            j=3;
        }
    }
    cout << '\n';
    return 0;
}