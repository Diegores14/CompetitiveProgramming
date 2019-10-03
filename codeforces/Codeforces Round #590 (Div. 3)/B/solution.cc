#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, temp;
    cin >> n >> k;
    list< int > l;
    set< int > s;
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        if( s.count(temp) == 0 )  {
            if( l.size() == k ) {
                int aux = l.back();
                s.erase( aux );
                l.pop_back();
            }
            s.insert( temp );
            l.push_front( temp );
        }
    }
    cout << l.size() << '\n';
    while( !l.empty() ) {
        cout << l.front();
        l.pop_front();
        cout << (l.empty()? '\n' : ' ' );
    }
    return 0;
}