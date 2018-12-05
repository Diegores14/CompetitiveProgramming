#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp, k;
    while(cin >> n >> m){
        vector< vector<int> > v(1000005);
        for(int i=1; i<=n; i++){
            cin >> temp;
            v[temp].emplace_back(i);
        }
        for(int i=0; i<m; i++){
            cin >> k >> temp;
            k--;
            if(v[temp].size() > k)
                cout << v[temp][k];
            else
                cout << 0;
            cout << '\n';
        }
    }
    return 0;
}