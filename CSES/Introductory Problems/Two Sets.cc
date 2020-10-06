#include <bits/stdc++.h>
using namespace std;
bool used[2000000];
long long n;
 
bool back( long long sum, int idx=1 ) {
    for( int i = n; i > 0; i-- ) {
        sum -= i;
        used[i] = true;
        if( sum < i ) {
            used[sum] = true;
            return true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin  >>  n;
    long long temp = n*(n+1)/2;
    if( temp%2 == 0) {
        cout << "YES\n";
        back( temp/2 );
        vector< int > s1, s2;
        for( int i = 1; i <= n; i++ )
            if(used[i]) s1.push_back(i);
            else s2.push_back(i);
        cout << s1.size() << '\n';
        for( int i = 0; i < s1.size(); i++ ) {
            cout << s1[i] << (i+1 == s1.size()? '\n' : ' ');
        }
        cout << s2.size() << '\n';
        for( int i = 0; i < s2.size(); i++ ) {
            cout << s2[i] << (i+1 == s2.size()? '\n' : ' ');
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}
