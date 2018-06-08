#include <bits/stdc++.h>
using namespace std;

int candies(int d, int k){
    if(k==1)return 1;
    if(k==2)return d+1;
    int res = 0;
    for(int i = d; i >= 0; i--)res+=candies(i,k-1);
    return res;
}

int main() {
    int t, d, k;
    cin >> t;
    while(t--){
        cin >> d >> k;
        cout << candies(d, k) << '\n';
    }
    return 0;
}
