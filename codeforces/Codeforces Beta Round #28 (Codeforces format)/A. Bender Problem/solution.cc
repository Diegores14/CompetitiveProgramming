#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
int n, m;
int rods[502], ans[502];
ii nails[502];

bool check1() {
    memset( ans, -1, sizeof ans );
    map< int, list< int > > s; 
    for( int i = 0; i < m; i++ ) {
        s[ rods[i] ].push_back(i);
    }
    int dist = abs(nails[n-1].first-nails[0].first) + abs(nails[n-1].second-nails[0].second);
    dist += abs(nails[1].first-nails[0].first) + abs(nails[1].second-nails[0].second);
    auto temp = s.lower_bound( dist );
    if( temp == s.end() ) return false;
    else {
        if( temp->first != dist ) return false;
        ans[0] = temp->second.front();
        temp->second.pop_front();
        //cout << temp->first << ' ' << s[temp->first].size() << '\n';
        if( temp->second.size() == 0 ) {
            s.erase( temp );
        }
    }
    for( int i = 2; i < n; i += 2 ) {
        dist = abs(nails[i-1].first-nails[i].first) + abs(nails[i-1].second-nails[i].second);
        dist += abs(nails[i+1].first-nails[i].first) + abs(nails[i+1].second-nails[i].second);
        temp = s.lower_bound( dist );
        if( temp == s.end() ) return false;
        else {
            if( temp->first != dist ) return false;
            ans[i] = temp->second.front();
            temp->second.pop_front();
            if( temp->second.size() == 0 ) {
                s.erase( temp );
            }
        }
    }
    return true;
}

bool check2() {
    memset( ans, -1, sizeof ans );
    map< int, list< int > > s; 
    for( int i = 0; i < m; i++ ) {
        s[ rods[i] ].push_back(i);
    }
    int dist = abs(nails[n-1].first-nails[0].first) + abs(nails[n-1].second-nails[0].second);
    dist += abs(nails[n-1].first-nails[n-2].first) + abs(nails[n-1].second-nails[n-2].second);
    auto temp = s.lower_bound( dist );
    if( temp == s.end() ) return false;
    else {
        if( temp->first != dist ) return false;
        ans[n-1] = temp->second.front();
        temp->second.pop_front();
        if( temp->second.size() == 0 ) {
            s.erase( temp );
        }
    }
    for( int i = 1; i < n-2; i += 2 ) {
        dist = abs(nails[i-1].first-nails[i].first) + abs(nails[i-1].second-nails[i].second);
        dist += abs(nails[i+1].first-nails[i].first) + abs(nails[i+1].second-nails[i].second);
        temp = s.lower_bound( dist );
        if( temp == s.end() ) return false;
        else {
            if( temp->first != dist ) return false;
            ans[i] = temp->second.front();
            temp->second.pop_front();
            if( temp->second.size() == 0 ) {
                s.erase( temp );
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> n >> m;
    for( int i = 0; i < n; i++ ) {
        cin >> nails[i].first >> nails[i].second;
    }
    for( int i = 0; i < m; i++ ) {
        cin >> rods[i];
    }
    if( check1() )  {
        cout << "YES\n";
        for( int i = 0; i < n; i++ ) {
            if( ans[i] != -1)
                cout << ans[i]+1;
            else 
                cout << -1;
            cout << ( n-1 == i? '\n' : ' ' );
        }
    } else {
        if( check2() ) {
            cout << "YES\n";
            for( int i = 0; i < n; i++ ) {
                if( ans[i] != -1)
                    cout << ans[i]+1;
                else 
                    cout << -1;
                cout << ( n-1 == i? '\n' : ' ' );
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}