#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int x[n], c[n];
    int A;
    for( int i = 0; i < n; i++ ) {
        cin >> x[i];
    }
    cin >> A;
    for( int i = 0; i < n; i++ ) {
        cin >> c[i];
    }
    priority_queue< int, vector< int > , greater< int > > q;
    long long ans = 0;
    long long force = k;
    for( int i = 0; i < n; i++ ) {
        q.push(c[i]);
        if( force < x[i] ) {
            while( !q.empty() && force < x[i] ) {
                force += A;
                ans += q.top();
                q.pop();
            }
            if( force < x[i] ) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}