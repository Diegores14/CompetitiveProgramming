#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k; 
    while(cin >> k){
        int twice = (k<<1);
        vector<pair<int, int>> v;
        for(int i = k + 1; i <= twice; i++){
            int a = k*i, b = i-k;
            if(a%b == 0){
                v.emplace_back(make_pair(a/b, i));
            }
        }
        cout << v.size() << '\n';
        for(auto i: v){
            cout << "1/" << k << " = " << "1/" << i.first << " + " << "1/" << i.second << '\n'; 
        }
    }
    return 0;
}