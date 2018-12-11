#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int f, r;
    cout << fixed << setprecision(2);
    while(cin >> f, f){
        cin >> r;
        long double ans = 0;
        vector<int> teethf(f), teethr(r);
        vector<long double> d;
        for(int &i: teethf){
            cin >> i;
        }
        for(int &i: teethr){
            cin >> i;
        }
        for(int &i: teethf){
            for(int &j: teethr){
                d.emplace_back((long double)j/i);
            }
        }
        sort(d.begin(), d.end());
        for(int i = 1; i < d.size(); i++){
            if(d[i] != d[i-1])
                ans = max(ans, d[i]/d[i-1]);
        }
        cout << ans << '\n';
    }
    return 0;
}