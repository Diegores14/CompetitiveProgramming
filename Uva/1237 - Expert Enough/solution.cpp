#include <bits/stdc++.h>
using namespace std;

struct node{
    string name;
    int L, H;
    node(){}
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q, L, H, temp;
    string name;
    cin >> t;
    while(t--){
        cin >> n;
        vector<node> v(n);
        for(int i = 0; i<n; i++){
            cin >> name >> L >> H;
            v[i].name = name;
            v[i].L = L;
            v[i].H = H;
        }
        cin >> q;
        for(int i = 0; i<q; i++){
            cin >> temp;
            int aux = 0;
            string ans;
            for(int i = 0; i < n; i++){
                if(v[i].L <= temp && temp <= v[i].H){
                    aux++;
                    ans = v[i].name;
                }
            }
            if(aux == 1){
                cout << ans << '\n';
            }else{
                cout << "UNDETERMINED\n";
            }
        }
        if(t){
            cout << '\n';
        }
    }
    return 0;
}