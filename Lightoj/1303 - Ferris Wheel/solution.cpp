#include <bits/stdc++.h>
using namespace std;
bool used[20][25];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    cin >> t;
    for( int r = 1; r <= t; r++) {
        cout << "Case " << r << ": ";
        cin >> n >> m;
        memset(used, 0, sizeof used);
        int seat[m];
        memset(seat, -1, sizeof seat);
        int answer = 0;
        int cant = 0;
        int limit = n*m;
        list<int> q;
        for(int i=0; i<n; i++) {
            q.push_back(i);
        }
        while((cant < limit || q.size() != n)) {
            for(int i = 0; i < m && (cant < limit || q.size() != n); i++) {
                if(seat[i] != -1) {
                    q.push_back(seat[i]);
                    seat[i] = -1;
                }
                for(int j : q) {
                    if(!used[j][i]) {
                        cant++;
                        seat[i] = j;
                        used[j][i] = true;
                        q.remove(j);
                        break;
                    }
                }
                answer += 5;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}