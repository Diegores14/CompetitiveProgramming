#include <bits/stdc++.h>
using namespace std;
const int tam = 205;
int g[tam];
bool used[tam];
string s;

void precompute() {
    g[0] = 0;
    for( int i = 1; i < tam; i++ ) {
        memset( used, 0, sizeof used );
        for( int j = 1; j <= i; j++ ) {
            int a = max(0, j-3), b = max(0, i-j-2);
            used[g[a]^g[b]] = true;
        }
        int k = 0;
        while( used[k] ) k++;
        g[i] = k;
    }
}

bool check1() {
    set<int> answers;
    int n = s.size();
    for( int i = 0; i < n; i++ ) {
        if( s[i] == 'X' ) continue;
        if( 0 < i && i+1 < s.size() && s[i-1] == 'X' && s[i+1] == 'X') {
            answers.insert(i);
            continue;
        }
        if( i+2 < s.size() && s[i+1] == 'X' && s[i+2] == 'X') {
            answers.insert(i);
            continue;
        }
        if( 1 < i && s[i-2] == 'X' && s[i-1] == 'X') {
            answers.insert(i);
            continue;
        }
    }
    int len = answers.size();
    int j = 1;
    for( int i: answers ) {
        cout << i+1 << (j==len? '\n' : ' ' );
        j++;
    }
    return len != 0;
}

bool check3() {
    int n = s.size();
    for( int i = 0; i < n; i++ ) {
        if( s[i] == 'X' ) continue;
        if( 0 < i && i+1 < s.size() && s[i-1] == 'X' && s[i+1] == 'X') {
            return true;
        }
        if( i+2 < s.size() && s[i+1] == 'X' && s[i+2] == 'X') {
            return true;
        }
        if( 1 < i && s[i-2] == 'X' && s[i-1] == 'X') {
            return true;
        }
    }
    return false;
}

bool check() {
    int len = 0;
    int ans = 0;
    for( int i = 0; i < s.size(); i++ ) {
        if( s[i] == 'X' ) {
            len = max(0, len-2 );
            ans ^= g[len];
            len = -2;
        } else {
            len++;
        }
    }
    len = max(0, len);
    ans ^= g[len];
    return ans != 0;
}

bool check2() {
    bool flag = false;
    if( check() ) {
        for( int i = 0; i < s.size(); i++ ) {
            if( s[i] == '.' ) {
                s[i] = 'X';
                if( !check3() && !check() ) {
                    cout << (flag? " " : "" ) << i+1;
                    flag = true;
                }
                s[i] = '.';
            }
        }
        cout << '\n';
        return true;
    }
    return false;
}

void solve() {
    if( !check1() ) {
        if( !check2() )
            cout << 0 << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    precompute();
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases <<  ": ";
        cin >> s; 
        solve();
    }
    return 0;
}