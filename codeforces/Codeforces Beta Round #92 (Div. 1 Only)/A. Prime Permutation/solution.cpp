#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
    for(int i=2; i*i <= n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    pair<int, char> v[256];
    for(int i=0; i<256; i++) {
        v[i].second = i;
    }
    cin >> s;
    for(char &i: s) {
        v[i].first++;
        i = ' ';
    }
    sort(v, v+255, greater< pair<int, char> >());
    for(int i=2; i<=s.size()/2; i++) {
        v[0].first--;
        if(v[0].first < 0) {
            cout << "NO\n";
            return 0;
        }
        s[i-1] = v[0].second;
    }
    for(int i=s.size()/2 + 1; i<=s.size(); i++) {
        if( !isprime(i) ) {
            v[0].first--;
            if(v[0].first < 0) {
                cout << "NO\n";
                return 0;
            }
            s[i-1] = v[0].second;
        }
    }
    cout << "YES\n";
    int l = 0;
    for(char &i: s) {
        if(i == ' ') {
            if(v[l].first == 0) {
                l++;
            }
            cout << v[l].second;
            v[l].first--;
        } else {
            cout << i;
        }
    }
    cout << '\n';
    return 0;
}