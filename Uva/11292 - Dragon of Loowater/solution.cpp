#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, m;
    while(cin >> n >> m, n || m){
        vector<int> v1(n), v2(m);
        for(int &i: v1){
            cin >> i;
        }
        for(int &i: v2){
            cin >> i;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        long long ans = 0;
        int j=0; 
        for(int i : v2){
            if(j == v1.size()){
                break;
            }
            if(v1[j] <= i){
                ans += i;
                j++;
            }
        }
        if(j != v1.size()){
            cout << "Loowater is doomed!\n";
        }else{
            cout << ans << '\n';
        }
    }
    return 0;
}