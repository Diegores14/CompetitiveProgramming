#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int k = 1; k<=t; k++){
        cin >> n;
        vector<int> v(n);
        for(int &i: v){
            cin >> i;
        }
        int a = 0, b = 1e7;
        while(b-a != 1){
            int mid = (a+b)>>1, temp = 0;
            int aux = mid;
            for(int i: v){
                if(i-temp > aux)
                    aux = -1;
                if(i-temp == aux){
                    aux--;
                }
                temp = i;
            }
            if(aux >= 0){
                b = mid;
            }else{
                a = mid;
            }
        }
        cout << "Case " << k << ": " << b << '\n';
    }
    return 0;
}