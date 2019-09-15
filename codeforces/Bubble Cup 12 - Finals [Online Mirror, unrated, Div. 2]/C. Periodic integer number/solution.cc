#include <bits/stdc++.h>
using namespace std;

string createString( int n ) {
    string ans = "1";
    for( int i = 1; i < n; i++ ) {
        ans.push_back('0');
    }
    return ans;
}

void otherAnswer( int n, int sz ) {
    string ans = createString( n );
    int limit = 0;
    while( limit < sz ) {
        limit += n;
        cout << ans;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    string s;
    cin >> n >> s;
    int sz = s.size();
    if( sz%n == 0 ) {
        bool Nueve = true, mayor = false, iguales = true;
        string ans = s.substr( 0, n );
        for( int i = 0; i < sz; i++ ) {
            mayor |= (iguales && s[i] > ans[i%n]);
            Nueve &= (s[i] == '9');
            iguales &= (s[i] == ans[i%n]);
        }
        if( Nueve ) otherAnswer( n, sz+1 ) ;
        else {
            if( mayor || iguales ) {
                int j = n-1;
                while( ans[j] == '9' ) {
                    ans[j] = '0';
                    j--;
                }
                ans[j]++;
            } 
            for( int i = 0; i < sz; i += n ) {
                cout << ans;
            }
            cout << '\n';
        }
    } else {
        otherAnswer( n, sz );
    }
    return 0;
}