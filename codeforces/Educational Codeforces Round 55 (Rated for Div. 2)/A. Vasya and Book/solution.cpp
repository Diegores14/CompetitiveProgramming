#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, x, y, d;
    cin >> t;
    while(t--){
        cin >> n >> x >> y >> d;
        long long aux = x, a=0, b = 0;
        bool flag1 = false, flag2 = false;
        while(aux>1){
            if(aux == y){
                flag1 = true;
                break;
            }
            aux -= d;
            a++;
        }
        aux = 1;
        if(aux == y){
            flag1 = true;
        }
        if(!flag1)
        while(aux < n){
            a++;
            aux += d;
            if(aux == y){
                flag1 = true;
                break;
            }
        }
        aux = n;
        if(aux == y){
            flag1 = true;
        }
        aux = x;
        while(aux<n){
            if(aux == y){
                flag2= true;
                break;
            }
            b++;
            aux += d;
        }
        aux = n;
        if(aux == y){
            flag2 = true;
        }
        if(!flag2)
        while(aux>1){
            b++;
            aux -= d;
            if(aux == y){
                flag2= true;
                break;
            }
        }
        aux == 1;
        if(aux == y){
            flag2 = true;
        }
        if(flag1 && flag2){
           cout << min(a, b) << '\n';
           continue;
        }
        if(flag1){
            cout << a << '\n';
            continue;
        }
        if(flag2){
            cout << b << '\n';
            continue;
        }
        cout << "-1\n";
    }
    return 0;
}