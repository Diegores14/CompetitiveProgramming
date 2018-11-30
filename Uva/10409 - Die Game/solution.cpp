#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n, n){
        vector<int> v(6);
        string s;
        for(int i=0; i<6; i++){
            v[i] = i+1;
        }
        while(n--){
            cin >> s;
            if(s == "north"){
                swap(v[0], v[4]);
                swap(v[4], v[5]);
                swap(v[5], v[1]);
            }
            if(s == "east"){
                swap(v[0], v[2]);
                swap(v[2], v[5]);
                swap(v[5], v[3]);
            }
            if(s == "south"){
                swap(v[0], v[1]);
                swap(v[1], v[5]);
                swap(v[5], v[4]);
            }
            if(s == "west"){
                swap(v[0], v[3]);
                swap(v[3], v[5]);
                swap(v[5], v[2]);
            }
        }
        cout << v[0] << '\n';
    }
    return 0;
}