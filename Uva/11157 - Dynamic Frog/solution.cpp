#include <bits/stdc++.h>
using namespace std;

struct node{
    int valor;
    char c;
    node(){}
    bool operator <(node other)const
    {
        return valor < other.valor;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, d;
    char c;
    cin >> t;
    for(int k=1; k<=t; k++){
        int ans = 0, temp = 0;
        cin >> n >> d;
        vector<node> v(n+1);
        for(int i=0; i<n; i++){
            cin >> v[i].c >> c >> v[i].valor;
        }
        v[n].c = 'B';
        v[n].valor = d;
        sort(v.begin(), v.end());
        for(int i=0; i<=n; i++){
            if(v[i].c == 'B'){
                ans = max(ans, v[i].valor - temp);
            }else{
                ans = max(ans, v[i+1].valor-temp);
            }
            temp = v[i].valor;
        }
        cout << "Case " << k << ": " << ans << '\n';
    }
    return 0;
}