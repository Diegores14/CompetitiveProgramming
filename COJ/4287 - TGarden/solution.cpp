#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, t, x, y;
    cin >> n >> m >> t;
    set< ii > used;
    queue< iii > q;
    int ans = n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        q.push(iii({0, ii({x, y})}));
        used.insert({ x, y});
    }
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        used.insert( { x, y} );
    }
    while(!q.empty()) {
        iii temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(temp.first < t && used.count({ temp.second.first + dx[i], temp.second.second + dy[i] }) == 0) {
                ans++;
                used.insert({ temp.second.first + dx[i], temp.second.second + dy[i] });
                q.push(iii( {temp.first+1, ii({temp.second.first + dx[i], temp.second.second + dy[i]})}));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}