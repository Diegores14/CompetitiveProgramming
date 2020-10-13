#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    multiset< int > s;
    int temp;
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        s.insert(-temp);
    }
    while( m-- ) {
        cin >> temp;
        auto it = s.lower_bound(-temp);
        if( it == s.end() )
            cout << -1 << '\n';
        else {
            cout << *it*-1 << '\n';
            s.erase(it);
        }
    }
    return 0;
}