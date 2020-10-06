#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    map< char, int > m, pos;
    m['A'] = 0;
    m['C'] = 0;
    m['G'] = 0;
    m['T'] = 0;
    pos['A'] = n;
    pos['C'] = n;
    pos['G'] = n;
    pos['T'] = n;
    pair< int, char > ans[n];
    for( int i = n-1; i >= 0; i-- ) {
        int mmin = 1e9;
        char c = 'A';
        for( auto j: m ) {
            if(mmin > j.second) {
                mmin = j.second;
                c = j.first;
            }
        }
        ans[i] = pair< int, char >( pos[c], c);
        m[s[i]] = mmin+1;
        pos[s[i]] = i;
    }
    int mmin = 1e9;
    char c = 'A';
    for( auto j: m ) {
        if(mmin > j.second) {
            mmin = j.second;
            c = j.first;
        }
    }
    int p = pos[c];
    while( p < n ) {
        cout << c;
        c = ans[p].second;
        p = ans[p].first;
    }
    cout << c << '\n';
    return 0;
}
