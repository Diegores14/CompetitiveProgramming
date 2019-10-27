#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    string answer;
    bool ok = true;
    for( int i = 0; i < s.size(); i++ ) {
        if( s[i] != '/' ) {
            answer.push_back( s[i] );
            ok = true;
        } else {
            if( ok ) {
                answer.push_back( s[i] );
                ok = false;
            }
        }
    }
    if( answer.size() == 1 ) {
        cout << answer << '\n';
    } else {
        if( answer[answer.size()-1] == '/' ) answer.pop_back();
        cout << answer << '\n';
    }
    return 0;
}