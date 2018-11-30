#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t, n, a, b, aux1, aux2;
    cin >> t;
    while(t--){
        bool isFinish = false;
        cin >> n >> a >> b;
        vector<int> v(n, 1);
        vector<int> pos(110);
        for(int i=0; i<110; i++){
            pos[i] = i;
        }
        for(int i=0; i<a; i++){
            cin >> aux1 >> aux2;
            pos[aux1] = aux2;
        }
        for(int i=0; i<b; i++){
            cin >> aux1;
            if(!isFinish){
                v[i%n] = pos[v[i%n] + aux1];
            }
            if(v[i%n] >= 100){
                isFinish =  true;
                v[i%n] = 100;
            }
        }
        for(int i=0; i<n; i++){
            cout << "Position of player " << i+1 << " is " << v[i] << ".\n";
        }
    }
    return 0;
}