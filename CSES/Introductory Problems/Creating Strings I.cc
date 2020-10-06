#include <bits/stdc++.h>
using namespace std;
int n;
int cant[255];
typedef pair< char, int > ci;
vector< ci > v;
vector< string > ans;
 
void solve( string &s, int idx=0 ) {
    if(idx == n)  {
        ans.push_back(s);
        return;
    }
    for( int i = 0; i < v.size(); i++ ) {
        if( v[i].second != 0 ) {
            v[i].second--;
            s.push_back(v[i].first);
            solve(s, idx+1);
            v[i].second++;
            s.pop_back();
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    n = s.size();
    for( int i = 0; i < n; i++ ) {
        cant[s[i]]++;
    }
    for( int i='a'; i <= 'z'; i++ ) {
        if( cant[i] != 0 ) {
            v.push_back( ci(char(i), cant[i]) );
        }
    }
    s = "";
    solve(s);
    cout << ans.size() << '\n';
    for( string i: ans ) {
        cout << i << '\n';
    }
    return 0;
}
