#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int temp;
    set<int> s;
    for(int i=0; i<4; i++) {
        cin >> temp;
        s.insert(temp);
    }
    cout << 4 - s.size() << '\n';
    return 0;
}