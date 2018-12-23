#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n, n){
        long long sum=0, temp, ans = 0;
        for(int i=0; i<n; i++){
            cin >> temp;
            sum += temp;
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(ans > 0){
            cout << "The maximum winning streak is " << ans << ".\n";
        }else{
            cout << "Losing streak.\n";
        }
    }
    return 0;
}