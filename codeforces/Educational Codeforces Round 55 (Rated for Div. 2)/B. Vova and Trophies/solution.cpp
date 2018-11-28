#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,  cont = 0, ans = 0;
    char c;
    cin >> n;
    vector<int> preffix(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> c;
        if(c == 'S'){
            preffix[i] = preffix[i-1] + 1;
        }else{
            cont++;
            preffix[i] = preffix[i-1];
        }
    }
    for(int i=0; i<=n; i++){
        int x = preffix[i]+1;
        int a = i, b = n+1;
        while(b-a != 1){
            int mid = (a+b)>>1;
            if(preffix[mid] <= x){
                a = mid;
            }else{
                b = mid;
            }
        }
        ans = max(ans, a-i);
    }
    if(n == 1)
        cout << cont << '\n';
    else
        cout << min(ans, cont) << '\n';
    return 0;
}