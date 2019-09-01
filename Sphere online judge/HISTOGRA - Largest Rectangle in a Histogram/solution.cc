#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    while( cin >> n, n ) {
        int v[n];
        stack< int > s;
        for( int i = 0; i < n; i++ ) {
            cin >> v[i];
        }
        int i = 0;
        long long area = 0;
        while( i < n ) {
            if( s.empty() || v[i] >= v[s.top()] ) {
                s.push(i++);
            } else {
                int tp = s.top();
                s.pop();
                area = max( area, 1LL*v[tp]*(s.empty()? i : i - s.top() - 1 ));
            }
        }
        while( !s.empty() ) {
            int tp = s.top();
            s.pop();
            area = max( area, 1LL*v[tp]*(s.empty()? i : i - s.top() - 1 ));
        }
        cout << area << '\n';
    }
    return 0;
}