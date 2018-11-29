#include <bits/stdc++.h>
using namespace std;

bool isSolution(int i, int j, int n){
    int aux = 0;
    int sum = 0;
    while(sum<n){
        if(aux&1){
            sum += j;
        }else{
            sum += i;
        }
        aux++;
    }
    return sum == n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int limit = (n>>1)+ (n&1);
    cout << n << ":\n";
    for(int i = 2; i <= limit; i++){
        if(isSolution(i, i-1, n)){
            cout << i << ',' << i-1 << '\n';
        }
        if(isSolution(i, i, n)){
            cout << i << ',' << i << '\n';
        }
    }
    return 0;
}