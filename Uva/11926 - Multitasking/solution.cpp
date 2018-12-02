#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a, b, c;
    while(cin >> n >> m, n || m){
        bool ans = true;
        bitset<1000001> calendar;
        for(int i = 0; i<n; i++){
            cin >> a >> b;
            for(int j=a; j < b; j++){
                if(calendar[j] == 1){
                    ans = false;
                }
                calendar[j] = 1;
            }
        }
        for(int i=0; i<m; i++){
            cin >> a >> b >> c;
            while(a < 1000001){
                for(int j=a; j<1000001 && j<b; j++){
                    if(calendar[j] == 1){
                        ans = false;
                    }
                    calendar[j]=1;
                }
                a += c;
                b += c;
            }
        }
        if(ans)
            cout << "NO ";
        cout << "CONFLICT\n";
    }
    return 0;
}