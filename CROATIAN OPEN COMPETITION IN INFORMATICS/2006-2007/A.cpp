#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x;
    set<int> numbers;
    for(int i = 0; i < 10; i++) {
        cin >> x;
        numbers.insert(x%42);
    }
    cout << numbers.size() << '\n';
    return 0;
}