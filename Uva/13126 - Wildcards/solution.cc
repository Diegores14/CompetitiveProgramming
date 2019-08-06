#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+50000;
const int K = 26;
int g[tam][K];
int f[tam];

struct ahoCorasick {
    
    list<int> o[tam];
    int size;
    ahoCorasick() {
        memset(g, -1, sizeof g);
        memset(f, -1, sizeof f); 
        size = 1;
    }
    void addString(string &s, int idx) {
        int v = 0;
        for( int i = 0; i < s.size(); i++ ) {
            char c = s[i] - 'a';
            if( g[v][c] == -1) {
                g[v][c] = size++;
            }
            v = g[v][c];
        }
        o[v].push_back(idx);
    }

    void build() {
        // firts I am going to G[0][a] = 0 to all a such that g[0][a] == -1
        for( int i = 0; i < K; i++ ) {
            if( g[0][i] == -1 ) g[0][i] = 0;
        }
        // all first characters f[s] = 0;
        queue< int > Q;
        for( int i = 0; i < K; i++) {
            if( g[0][i] != 0 ) {
                Q.push( g[0][i] );
                f[ g[0][i] ] = 0;
            }
        }
        //cout << "Debug\n";
        while( !Q.empty() ) {
            int r = Q.front();
            Q.pop();
            for(int i = 0; i < K; i++) {
                int s = g[r][i];
                if( s != -1 ) {
                    Q.push( s );
                    int state = f[r];
                    while( g[state][i] == -1) state = f[state];
                    f[ s ] = g[state][i];
                    for(int &j: o[ f[ s ] ] ) 
                        o[ s ].push_back(j);
                }
            }
        }
        //cout << "Debug\n";
    }
    int go(int v, char ch) {
        char c = ch - 'a';
        while( g[v][c]  == -1 ) v = f[v];
        return g[v][c];
    }
};

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    while( cin >> s1 >> s2 ) {
        //cout << "Hello\n";
        if( s1.size() < s2.size() ) { cout << 0 << '\n'; continue; }
        vector< string > words;
        vector< int > lends, cnt(s1.size(), 0);
        
        for( int i = 0; i < s2.size(); i++ ) {
            if( s2[i] != '?' ) {
                string temp;
                while( i < s2.size() && s2[i] !=  '?' ) {
                    temp += s2[i++];
                }
                words.push_back(temp);
                lends.push_back(i-1);
            }
        }
        //cout << "Hello\n";
        ahoCorasick aho;
        for( int i = 0; i < words.size(); i++ ) {
            aho.addString( words[i], i );
        }
        //cout << "Hello\n";
        aho.build();
        int cur = 0;
        for( int i = 0; i < s1.size(); i++ ) {
            //cout << i << '\n';
            cur = aho.go( cur, s1[i] );
            if( aho.o[cur].size() ) {
                for(int &j : aho.o[cur] ) {
                    if( i >= lends[j] ) {
                        cnt[ i - lends[j] ]++;
                    }
                }
            }
        }
        //cout << "Hello\n";
        int ans = 0;
        for( int i = 0; i <= s1.size() - s2.size(); i++ ) {
            ans += lends.size() == cnt[i];
        }
        cout << ans << '\n';
    }
    return 0;
}