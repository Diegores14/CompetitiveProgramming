#include <bits/stdc++.h>
using namespace std;
vector< vector< int > > ans;

void precalculation( vector<int> &v ) {
    set< int > s1, s2;
    for(int i = 0; i < 8; i++) {
        if(s1.count(i+v[i]) == 0 && s2.count(i-v[i]) == 0) {
            s1.insert(i+v[i]);
            s2.insert(i-v[i]);
        } else {
            return;
        }
    }
    ans.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, x, y;    
    vector< int > v(8);
    for(int i = 0; i < 8; i++) v[i] = i;
    do {
        precalculation(v);
    } while(next_permutation(v.begin(), v.end()));
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> x >> y;
        if(cases != 1) cout << '\n';
        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        x--; y--;
        int k = 1;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i][y] == x) {
                if(k < 10) {
                    cout << ' ';
                }
                cout << k++ << "     ";
                for(int j : ans[i]) {
                    cout << ' ' << j+1;
                }
                cout << '\n';
            }
        }
    }
    return 0;
}