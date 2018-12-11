#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long  n, s;
    int mmin = 1000000000;
    long long sum = 0;
    cin >> n >> s;
    vector<int> v(n);
    for(int &i: v){
        cin >> i;
        sum += i;
        mmin = min(mmin, i);
    }
    if(sum >= s){
        long long temp = 0;
        for(int &i : v){
            temp += i-mmin;
        }
        if(temp >= s){
            cout << mmin << '\n';
        }else{
            mmin = mmin - ((s - temp)/n + (((s - temp)%n != 0 )? 1 : 0));
            cout << mmin << '\n';
        }
    }else{
        cout << "-1\n";
    }
    return 0;
}