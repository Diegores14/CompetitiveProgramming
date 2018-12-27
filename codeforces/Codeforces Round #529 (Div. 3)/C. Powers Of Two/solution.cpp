#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, cont=0;
    cin >> n >> k;
    if(n < k){
        cout << "NO\n";
    }else{
        vector<int> v(32, 0);
        for(int i=0; i<32; i++){
            if(n & (1<<i)){
                v[i] = 1;
                cont++;
            }
        }
        if(cont > k){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(int i=31; k>cont && i>0; i--){
                while(v[i]>0 && k>cont){
                    v[i-1]+=2;
                    v[i]--;
                    cont++;
                }
            }
            cont = 0;
            for(int i=0; i<32; i++){
                if(v[i]){
                    while(v[i]--){
                        cont++;
                        cout << (1<<i) << ((cont==k)? "\n": " ");
                    }
                }
            }
            cout << '\n';
        }
    }
    return 0;
}