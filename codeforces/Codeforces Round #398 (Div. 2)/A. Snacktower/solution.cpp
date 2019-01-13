#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin >> n;
    int limit = n, temp;
    vector<bool> fell(n+1, false);
    for(int i=0; i<n; i++) {
        cin >> temp;
        fell[temp] = true;
        if(fell[limit]) {
            cout << limit;
            limit--;
            while(fell[limit]) {
                cout << ' ' << limit;
                limit--;
            }
        }
        cout << '\n';
    }
    return 0;
}