#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    set<int> s;
    int cont = 0;
    for(int &i : v1) {
        cin >> i;
        s.insert(i);
    }
    for(int &i : v2){
        cin >> i;
        s.insert(i);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(s.count(v1[i]^v2[j])){
                cont++;
            }
        }
    }
    if(cont&1) {
        cout << "Koyomi\n";
    }else {
        cout << "Karen\n";
    }
    return 0;
}