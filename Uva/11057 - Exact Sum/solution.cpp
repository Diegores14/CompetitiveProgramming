#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    bool sal = true;
    while(cin >> n){
        vector<int> v(n);
        for(int &i: v){
            cin >> i;
        }
        sort(v.begin(), v.end());
        int ans1, ans2;
        cin >> m;
        for(int i=0; i<n; i++){
            int a = i, b = n;
            int k = m-v[i];
            while(b-a != 1){
                int mid = (a+b)>>1;
                if(k <= v[mid])
                    b = mid;
                else
                    a = mid;
            }
            if(b != n && v[b] == k){
                ans1 = v[i];
                ans2 = k;
            }
        }
        cout << "Peter should buy books whose prices are " << ans1 << " and " << ans2 << ".\n\n";
    }
    return 0;
}