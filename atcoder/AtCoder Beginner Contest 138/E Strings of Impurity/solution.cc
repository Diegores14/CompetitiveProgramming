#include <bits/stdc++.h>
using namespace std;
const int tam = 26;
vector< vector< int > > v(tam);
string s, t;
int n;

int bs(int pos, int c) {
    int l = -1, r = v[c].size();
    while( r-l != 1 ) {
        int mid = (l+r)/2;
        if( v[c][mid] >= pos ) {
            r = mid; 
        } else {
            l = mid;
        }
    }
    return r == v[c].size()? v[c][0] : v[c][r];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t;
    n = s.size();
    for( int i = 0; i < n; i++ ) {
        v[s[i]-'a'].emplace_back(i);
    }
    for( int i = 0; i < t.size(); i++ ) {
        if(v[ t[i]-'a' ].size() == 0 ) {
            cout << -1 << '\n';
            return 0;
        }
    }
    long long ans = 0;
    int pointer = 0;
    //cout << v['t'-'a'][0] << '\n';
    for( char i: t ) {
        int temp = bs(pointer, i-'a');
        //cout << i << ' ' << pointer << ' ' << temp << '\n';
        if(temp < pointer) {
            ans += n;
        }
        pointer = temp + 1;
    }
    //cout << '\n';
    cout << ans + pointer << '\n';
    return 0;
}