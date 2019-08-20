#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6+50;
int len = 1;
bool terminator[tam];
int go[tam][26];
int fail[tam];
vector< list<int> > go2, out;
int dp[tam];

struct ahoCorasick {
    ahoCorasick() {
        memset( go, -1, sizeof go );        
        memset( dp, -1, sizeof dp );
        memset( terminator, 0, sizeof terminator );
        go2.assign( tam, list<int>() );
        out.assign( tam, list<int>() );
        len = 1;
    }
    void add_string( const string &s ) {
        int state = 0;
        for( int i = 0; i < s.size(); i++) {
            if( go[state][s[i]-'a'] == -1 ) {
                go[state][s[i]-'a'] = len++;
            }
            state = go[state][s[i]-'a'];
        }
        terminator[state] = true;
        out[state].push_back(state);
    }
    void build() {
        queue< int > q;
        for( int i = 0; i < 26; i++ ) {
            if( go[0][i] == -1 ) go[0][i] = 0; 
            else { q.push( go[0][i] ); fail[ go[0][i] ] = 0; }
        }
        while( !q.empty() ) {
            int r = q.front();
            q.pop();
            for( int i = 0; i < 26; i++ ) {
                if( go[r][i] != -1 ) {
                    q.push( go[r][i] );
                    int state = fail[r];
                    while( go[state][i] == -1 ) state = fail[ state ];
                    fail[ go[r][i] ] = go[state][i];
                    for( int &j: out[ go[state][i] ] ) {
                        go2[ j ].push_back( go[r][i] );
                        out[ go[r][i] ].push_back(j);
                    }
                }
            }
        }
    }
    int solve(int idx) {
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = 0;
        for( int i = 0; i < 26; i++ ) {
            if( go[idx][i] != -1 );
                dp[idx] = max( dp[idx], solve( go[idx][i] ) );
        }
        for( int i: go2[idx] ) {
            dp[idx] = max( dp[idx], solve( i ) );
        }
        if( terminator[idx] ) {
            dp[idx]++;
        }
        return dp[idx];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k = 1;
    while( cin >> n, n ) {
        string s;
        ahoCorasick ac;
        for( int i = 0; i < n; i++ ) {
            cin >> s;
            ac.add_string(s);
        }
        ac.build();
        cout << ac.solve(0) << '\n';
    }
    return 0;
}