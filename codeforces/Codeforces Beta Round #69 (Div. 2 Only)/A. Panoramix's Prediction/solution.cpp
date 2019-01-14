#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<bool> criba(100, true);
    criba[0] = criba[1] = false;
    vector<int> v;
    v.emplace_back(2);
    int n, m;
    cin >> n >> m;
    for(int i=4; i<100; i+=2) {
        criba[i] = false;
    }
    for(int i=3; i<100; i++) {
        if(criba[i]) {
            v.emplace_back(i);
            for(int j=i*i; j<100; j+=i) {
                criba[j] = false;
            }
        }
    }
    bool ans = false;
    for(int i=0; i<v.size(); i++) {
        if(v[i] == n && v[i+1] == m) {
            ans = true;
        }
    }
    cout << (ans? "YES\n" : "NO\n");
    return 0;
}