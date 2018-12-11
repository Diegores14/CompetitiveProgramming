#include <bits/stdc++.h>
using namespace std;

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    char c;
    while(cin >> n, n){
        cin >> c;
        vector<int> v(n);
        vector<int> pos(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
            pos[v[i]] = i;
        }
        bool ans = false;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp = (v[j]<<1) - v[i];
                if( temp < n && temp >= 0 && j < pos[temp]){
                    ans = true;
                    break;
                }
            }
        }
        if(!ans){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
    return 0;
}