#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    map<int, int> m;
    for(int i=0; i<n; i++) {
        cin >> temp;
        m[temp]++;
    }
    list<int> increasing, decreasing;
    for(auto &i: m) {
        if(i.second > 2) {
            cout << "NO\n";
            return 0;
        }
        increasing.push_back(i.first);
        if(i.second == 2) {
            decreasing.push_front(i.first);
        }
    }
    cout << "YES\n";
    cout << increasing.size() << '\n';
    for(int i : increasing) {
        cout << i << " ";
    }
    cout << '\n' << decreasing.size() << '\n';
    for(int i : decreasing) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}