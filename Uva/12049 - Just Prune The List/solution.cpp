#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, temp;
    cin >> t;
    while(t--){
        cin >> n >> m;
        long long ans = 0;
        multiset<int> s1, s2;
        for(int i=0; i<n; i++){
            cin >> temp;
            s1.insert(temp);
        }
        for(int i=0; i<m; i++){
            cin >> temp;
            s2.insert(temp);
        }
        multiset<int>::iterator it1, it2;
        it1 = s1.begin();
        it2 = s2.begin();
        while(it1 != s1.end() && it2 != s2.end()){
            if(*it1 != *it2){
                if(*it1 < *it2){
                    s1.erase(it1++);
                }else{
                    s2.erase(it2++);
                }
                ans++;
            }else{
                it1++;
                it2++;
            }
        }
        ans += abs((int)s1.size() - (int)s2.size());
        cout << ans << '\n';
    }
    return 0;
}