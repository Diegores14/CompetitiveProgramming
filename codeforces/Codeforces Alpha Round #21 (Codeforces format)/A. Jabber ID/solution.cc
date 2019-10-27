#include <bits/stdc++.h>
using namespace std;

bool check( string &s ) {
    if( s.size() == 0 || 16 < s.size() ) return false;
    int ans = 0; 
    for( char &i : s ) {
        ans += ( ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z') );
        ans += ('0' <= i && i <= '9');
        ans += (i == '_');
    }
    return ans == s.size();
}

bool check1( string &s ) {
    if( s.size() == 0 || 32 < s.size() ) return false;
    int ans = 0; 
    int len = 0;
    for( char &i : s ) {
        if( i == '.' ) {
            if( len == 0 ) return false;
            len = 0;
            ans++;
            continue;
        }
        ans += ( ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z') );
        ans += ('0' <= i && i <= '9');
        ans += (i == '_');
        len++;
        if( len > 16 ) return false;
    }
    return ans == s.size() && len ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string username, hostname, resource, s;
    cin >> s;
    long long pos = s.find('@');
    if( pos > s.size() ) {
        //cout << "DEgug1\n";
        cout << "NO\n";
        return 0;
    }
    username = s.substr( 0, pos );
    if( !check(username) ) {
        //cout << "DEgug2\n";
        cout << "NO\n";
        return 0;
    }
    s = s.substr( pos+1 );
    if( s.size() > s.find( '/' ) ) {
        pos = s.find( '/' );
        hostname = s.substr( 0, pos );
        resource = s.substr( pos+1 );
        if( !check(resource) ) {
            //cout << "DEgug3\n";
            cout << "NO\n";
            return 0;
        }
    } else {
        hostname = s;
    }
    if( !check1( hostname ) ) {
        //cout << "DEgug4\n";
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}