#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k = 1;
    while(cin >> n >> m, n || m){
        int mmin = 1000000000, temp;
        for(int i=0; i<n; i++){
            cin >> temp;
            mmin = min(mmin, temp);
        }
        for(int i=0; i<m; i++){
            cin >> temp;
        }
        cout << "Case " << k << ": ";
        if(n-m>0){
            cout << n-m << ' ' << mmin << '\n';
        }else{
            cout << "0\n";
        }
        k++;
    }
    return 0;
}