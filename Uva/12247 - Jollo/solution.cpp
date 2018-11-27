#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int player1[3], player2[2];
    while(cin >> player1[0] >> player1[1] >> player1[2] >> player2[0] >> player2[1],
         player1[0] && player1[1] && player1[2] && player2[0] && player2[1]){
        set<int> s;
        s.insert(player1[0]);
        s.insert(player1[1]);
        s.insert(player1[2]);
        s.insert(player2[0]);
        s.insert(player2[1]);
        int cant1 = 0, cant2 = 0;
        for(int i: player1){
            if(player2[0] > i)
                cant1++;
            if(player2[1] > i)
                cant2++;
        }
        if(cant1 == 3 && cant2 == 3){
            for(int i=1; i<53; i++)
                if(!s.count(i)){
                    cout << i << '\n';
                    break;
                }
                continue;
        }
        if((cant1 == 3 && cant2 == 2) || (cant1 == 2 && cant2 == 3)){
            int ans = -1;
            for(int i = 1; i<53; i++){
                int aux = 0;
                if(!s.count(i))
                for(int j: player1){
                    if(i > j){
                        aux++;
                    }
                }
                if(aux >= 2 ){
                    ans = i;
                    break;
                }
            }
            cout << ans << '\n';
            continue;
        }
        if((cant1 == 3) || (cant2 == 3)){
            int ans = -1;
            for(int i = 1; i<53; i++){
                int aux = 0;
                if(!s.count(i))
                for(int j: player1){
                    if(i > j){
                        aux++;
                    }
                }
                if(aux == 3){
                    ans = i;
                    break;
                }
            }
            cout << ans << '\n';
            continue;
        }
        if(cant1 == 2 && cant2 == 2){
            int ans = -1;
            for(int i = 1; i<53; i++){
                int aux = 0;
                if(!s.count(i))
                for(int j: player1){
                    if(i > j){
                        aux++;
                    }
                }
                if(aux >= 2){
                    ans = i;
                    break;
                }
            }
            cout << ans << '\n';
            continue;
        }
        cout << "-1\n";
    }
    return 0;
}