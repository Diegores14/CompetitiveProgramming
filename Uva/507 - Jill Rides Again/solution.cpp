#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int k = 1; k <= t; k++){
        long long sum = 0, ans = -1, x = -1, y = -1, mmax = -1, i=0, j=0;
        cin >> n;
        vector<int> v(n-1);
        for(int &r: v){
            cin >> r;
            sum += r;
            if(sum > ans || (sum == ans && j-i > mmax)){
                x = i;
                y = j;
                ans = sum;
                mmax = j-i;
            }
            j++;
            if(sum < 0 ){
                sum = 0;
                i = j;
            }
        }
        if(ans == -1){
            cout << "Route " << k << " has no nice parts\n";
        }else{
            cout << "The nicest part of route " <<  k << " is between stops " << x+1 << " and " << y+2 << '\n';
        }
    }
    return 0;
}