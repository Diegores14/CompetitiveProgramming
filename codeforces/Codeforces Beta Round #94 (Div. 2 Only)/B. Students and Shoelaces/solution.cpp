#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> cant(n, 0) ;
    vector< list<int> > v(n);
    for(int i=0; i<m; i++){ 
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
        cant[a]++;
        cant[b]++;
    }
    int ans = -1;
    bool flag = true;
    while(flag) {
        ans++;
        flag = false;
        list<int> temp;
        for(int i=0; i<n; i++) {
            if(cant[i] == 1) {
                cant[i] = 0;
                temp.push_back(i);
                flag = true;
            }
        }
        for(int i: temp) {
            for(int j: v[i]) {
                    cant[j]--;
                }
        }
    }
    cout << ans << '\n'; 
    return 0;
}