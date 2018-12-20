#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    while(cin >> n, n){
        int cant = 0;
        for(int i=0; i<n; i++){
            cin >> temp;
            if(temp != 0){
                if(cant){
                    cout << ' ';
                }
                cout << temp;                
                cant++;
            }
        }
        if(cant == 0)
            cout << 0;
        cout << '\n';
    }
    return 0;
}