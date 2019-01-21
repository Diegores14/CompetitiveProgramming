#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<char> memo(26, -1);
    int n, m, x;
    char temp, c;
    cin >> n >> m >> x;
    x *= x;
    map<char, vector< pair<int,int> > > se;
    vector< pair<int,int> > v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> c;
            if(c != 'S')
                se[c].emplace_back( make_pair(i, j) );
            else {
                v.emplace_back( make_pair(i,j) );
            }
        }
    }
    int k; 
    long long ans = 0;
    cin >> k;
    while(k--) {
        cin >> c;
        temp = tolower(c);
        if(temp != c) {
            if(se.count(temp) && v.size()!=0) {
                bool res = true;
                if(memo[temp-'a'] == -1) {
                    for(auto &i: v) {
                        for(auto &j: se[temp]){
                            long long aux = (j.first - i.first) * (j.first - i.first) +
                                            (j.second - i.second) * (j.second - i.second);
                            if(x >= aux) {
                                res = false;
                                break;
                            }
                        }
                    }
                    memo[temp-'a'] = res;
                }
                ans += memo[temp-'a'];
            } else {
                cout << "-1\n";
                return 0;
            }
        } else {
            if(se.count(c)==0) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}