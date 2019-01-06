#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp;
    cin >> n >> m;
    vector<bool> visit1(n, false), visit2(m, false);
    for(int i=0; i<n; i++){
        cin >> temp;
        visit1[temp] = true;
    }
    for(int i=0; i<m; i++){
        cin >> temp;
        visit2[temp] = true;
    }
    for(int i=1; i<100; i++){
        temp = i%10;
        int temp2 = (i/10)%10;
        if((visit1[temp] || visit1[temp2]) && (visit2[temp] || visit2[temp2])){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}