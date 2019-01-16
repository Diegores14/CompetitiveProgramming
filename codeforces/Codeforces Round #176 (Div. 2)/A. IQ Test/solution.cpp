#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<string> v(4);
    for(string &i: v) {
        cin >> i;
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int temp = (v[i][j]=='#'? 1 : 0);
            temp += (v[i+1][j]=='#'? 1 : 0);
            temp += (v[i][j+1]=='#'? 1 : 0);
            temp += (v[i+1][j+1]=='#'? 1 : 0);
            if(temp == 0 || temp == 3 || temp == 1 || temp == 4) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}