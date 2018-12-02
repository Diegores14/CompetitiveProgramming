#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    while(cin >> n, n){
        int a = 0, b = 0;
        bool flag = true;
        for(int i=0; i<31; i++){
            if((n>>i)&1){
                if(flag)
                    a |= (1<<i);
                else
                    b |= (1<<i);
                flag = !flag;
            }
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}