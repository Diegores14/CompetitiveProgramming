#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, b, w;
    cin >> q;
    while(q--) {
        vector< ii > ans;
        cin >> b >> w;
        if( min(b, w)*3 + 1 >= max(b, w) ) {
            cout << "YES\n";
            if( b > w ) {
                int i = 2;
                while( w ) {
                    ans.emplace_back( ii(2, i-1) );
                    ans.emplace_back( ii(2, i) );
                    i += 2;
                    w--;
                    b--;
                }
                if( b ) {
                    ans.emplace_back( ii(2, i-1) );
                    b--;
                }
                for( int j = 2; j < i && b; j += 2 ) {
                    ans.emplace_back( ii(1, j) );
                    b--;
                }
                for( int j = 2; j < i && b; j += 2 ) {
                    ans.emplace_back( ii(3, j) );
                    b--;
                }
            } else {
                int i = 2;
                while( b ) {
                    ans.emplace_back( ii(3, i-1) );
                    ans.emplace_back( ii(3, i) );
                    i += 2;
                    w--;
                    b--;
                }
                if( w ) {
                    ans.emplace_back( ii(3, i-1) );
                    w--;
                }
                for( int j = 2; j < i && w; j += 2 ) {
                    ans.emplace_back( ii(2, j) );
                    w--;
                }
                for( int j = 2; j < i && w; j += 2 ) {
                    ans.emplace_back( ii(4, j) );
                    w--;
                }
            }
            for(auto &i: ans) {
                cout << i.first << ' ' << i.second << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}