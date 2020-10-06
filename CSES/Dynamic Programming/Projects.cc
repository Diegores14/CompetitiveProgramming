#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int a, b, p;
};
long long dp[400005];
node v[200005];
vector<node> a[400005];
vector<int> values;
map< int, int > pos;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i].a >> v[i].b >> v[i].p;
        values.push_back(v[i].a);
        values.push_back(v[i].b);
    }
    values.push_back(1000000009);
    sort( values.begin(), values.end() );
    auto it = unique( values.begin(), values.end() );
    values.resize(it-values.begin());
    for( int i = 0; i < values.size(); i++ ) {
        pos[values[i]] = i;
    }
    for( int i = 0; i < n; i++ ) {
        a[pos[v[i].a]].push_back(v[i]);
    }
    for( int i = values.size()-1; i >= 0; i-- ) {
        dp[i] = dp[i+1];
        for( node j: a[i] ) {
            int l = lower_bound(values.begin(), values.end(), j.b+1)-values.begin();
            dp[i] = max(dp[i], dp[l]+j.p);
        }
    }
    cout << dp[0] << '\n';
    return 0;
}
