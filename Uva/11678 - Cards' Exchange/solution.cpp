#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    while(cin >> a >>  b, a && b){
        set<int> s1, s2;
        int aux;
        for(int i=0; i<a; i++){
            cin >> aux;
            s1.insert(aux);
        }
        for(int i=0; i<b; i++){
            cin >> aux;
            s2.insert(aux);
        }
        if(s1.size() <= s2.size()){
            int ans = 0;
            for(int i: s1){
                if(!s2.count(i))
                    ans++;
            }
            cout << ans << '\n';
        }else{
            int ans = 0;
            for(int i: s2){
                if(!s1.count(i))
                    ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}