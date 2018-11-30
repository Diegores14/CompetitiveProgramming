#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, b;
    while(cin >> n >> b, n || b){
        vector<int> v(b);
        set<int> s;
        for(int &i : v){
            cin >> i;
        }
        for(int i=0; i<b; i++){
            for(int j=i; j<b; j++){
                s.insert(abs(v[j] - v[i]));
            }
        }
        if(s.size() == n+1)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}