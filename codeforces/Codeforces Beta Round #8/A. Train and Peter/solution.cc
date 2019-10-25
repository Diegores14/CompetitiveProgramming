#include <bits/stdc++.h>
using namespace std;

bool check( string s, string a, string b ) {
    int i = 0;
    bool ok = false;
    while( i < s.size() && !ok ) {
        ok = (i+b.size() <= s.size());
        for( int j = 0; j < a.size() && i+j < s.size(); j++ ) {
            if( s[i+j] != a[j] ) {
                ok = false;
                break;
            }
        }
        if( ok )
            i += a.size();
        else 
            i++;
    }
    ok = false;
    while( i < s.size() && !ok ) {
        ok = (i+b.size() <= s.size());
        for( int j = 0; j < b.size() && i+j < s.size(); j++ ) {
            if( s[i+j] != b[j] ) {
                ok = false;
                break;
            }
        }
        i++;
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, a, b;
    bool ans1, ans2;
    cin >> s >> a >> b;
    ans1 = check( s, a, b );
    reverse( s.begin(), s.end() );
    ans2 = check( s, a, b );
    if( ans1 && ans2 ) {
        cout << "both\n";
    } else {
        if( ans1 ) {
            cout << "forward\n";
        }
        if( ans2 ) {
            cout << "backward\n";
        }
    }
    if( !ans1 && !ans2 ) {
        cout << "fantasy\n";
    }
    return 0;
}