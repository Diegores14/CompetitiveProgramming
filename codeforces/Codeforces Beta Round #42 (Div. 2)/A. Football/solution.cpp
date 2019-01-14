#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    string temp;
    map<string, int> m;
    for(int i=0; i<n; i++) {
        cin >> temp;
        m[temp]++;
    }
    for(auto i: m) {
        if(ans < i.second) {
            temp = i.first;
            ans = i.second;
        }
    }
    cout << temp << '\n';
    return 0;
}