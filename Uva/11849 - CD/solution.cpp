#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, aux;
    while(cin >> n >> m, n || m){
        unordered_set<int> s;
        long long ans = 0;
        for(int i=0; i < n; i++){
            cin >> aux;
            s.insert(aux);
        }
        for(int i=0; i < n; i++){
            cin >> aux;
            if(s.count(aux))
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}