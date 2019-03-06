#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, d, temp;
    cin >> n >> m >> d;
    set< pair<int, int> > se;
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        cin >> temp;
        se.insert( {temp, i} );
    }
    int ansn = 0;
    while(!se.empty()) {
        ansn++;
        ans[se.begin()->second] = ansn;
        temp = se.begin()->first;
        se.erase( se.begin() );
        while(true){
            auto it = se.lower_bound( {temp+d+1, 0} );
            if( it == se.end() ) {
                break;
            }
            ans[it->second] = ansn;
            temp = it->first;
            se.erase( it );
        }
    }
    cout << ansn << '\n';
    for(int i=0; i<n; i++) {
        cout << ans[i] << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}