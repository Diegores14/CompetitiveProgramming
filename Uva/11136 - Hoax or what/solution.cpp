#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, aux, limit;
    while(cin >> n, n){
        multiset<int> s;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            cin >> limit;
            for(int j = 0; j < limit; j++){
                cin >> aux;
                s.insert(aux);
            }
            multiset<int>::iterator it1 = s.begin(), it2 = s.end();
            it2--;
            ans += (*it2 - *it1);
            s.erase(it1);
            s.erase(it2);
        }
        cout << ans << '\n';
    }
    return 0;
}