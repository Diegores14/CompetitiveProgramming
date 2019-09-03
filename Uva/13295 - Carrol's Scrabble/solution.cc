#include <bits/stdc++.h>
using namespace std;
unordered_map< string, int > values;
unordered_map< string, list< string > > cycles;
int n, q, pt[26];
typedef pair< int, int > ii;

void solve( string word1, string word2 ) {
    if( word1.size() != word2.size() ) {
        cout << word1 << " TO " << word2 << " IMPOSSIBLE\n";
        return;
    }
    if( word1 == word2 ) {
        cout << word1 << " TO " << word2 << " 0 0\n";
        return;
    }
    queue< string > Q;
    unordered_map< string, ii > dist;
    Q.push( word1 );
    dist[ word1 ] = ii( 0, 0 );
    while( !Q.empty() ) {
        string cur = Q.front(); Q.pop();
        ii dt = dist[cur];
        if( cur == word2 ) {
            cout << word1 << " TO " << word2 << ' ' << dt.first << ' ' << dt.second - values[cur] << '\n';
            return;
        }
        for( int i = 0; i < cur.size(); i++ )  {
            char c = cur[i];
            for( char j = 'a'; j <= 'z'; j++ ) {
                if( j == c ) continue;
                cur[i] = j;
                if( values.count(cur) == 0 ) continue;
                if( dist.count(cur) ) {
                    if( dist[cur].first == dt.first + 1 )
                        dist[cur].second = max( dist[cur].second, dt.second + values[cur] );
                } else {
                    Q.push(cur);
                    dist[cur] = ii( dt.first+1, dt.second + values[cur] );
                }
            }
            cur[i] = c;
        }
        sort( cur.begin(), cur.end() );
        for( string &i: cycles[cur] ) {
            if( dist.count(i) ) {
                if( dist[i].first == dt.first + 1 )
                dist[i].second = max( dist[i].second, dt.second + values[i] );
            } else {
                Q.push(i);
                dist[i] = ii( dt.first+1, dt.second + values[i] );
            }
        }
    }
    cout << word1 << " TO " << word2 << " IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for( char i: {'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'} ) {
        pt[i-'a'] = 1;
    }
    for( char i: {'d', 'g'} ) {
        pt[i-'a'] = 2;
    }
    for( char i: {'b', 'c', 'm', 'p'} ) {
        pt[i-'a'] = 3;
    }
    for( char i: {'f', 'h', 'v', 'w', 'y'} ) {
        pt[i-'a'] = 4;
    }
    for( char i: {'k'} ) {
        pt[i-'a'] = 5;
    }
    for( char i: {'j', 'x'} ) {
        pt[i-'a'] = 8;
    }
    for( char i: {'q', 'z'} ) {
        pt[i-'a'] = 10;
    }
    while( cin >> n ) {
        string s;
        values.clear();
        cycles.clear();
        for( int i = 0; i < n; i++ ) {
            cin >> s;
            int val = 0;
            for( char &j: s) {
                val += pt[j-'a'];
            }
            values[s] = val;
            string temp = s;
            sort( temp.begin(), temp.end() );
            cycles[temp].push_back(s);
        }
        cin >> q;
        while( q-- ) {
            string word1, temp, word2;
            cin >> word1 >> temp >> word2;
            solve(word1, word2);
        }
    }
    return 0;
}