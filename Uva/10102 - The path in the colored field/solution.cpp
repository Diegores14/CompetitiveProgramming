#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    char temp;
    while(cin >> n){
        vector<int> pos1[2];
        vector<int> pos3[2];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> temp;
                if(temp == '1'){
                    pos1[0].emplace_back(j);
                    pos1[1].emplace_back(i);
                }
                if(temp == '3'){
                    pos3[0].emplace_back(j);
                    pos3[1].emplace_back(i);
                }
            }
        }
        int mmin = -1;
        for(int i=0; i<pos1[0].size(); i++){
            int dis = 1<<30;
            for(int j=0; j < pos3[0].size(); j++){
                dis = min(dis, abs(pos1[0][i]-pos3[0][j]) + abs(pos1[1][i]-pos3[1][j]));
            }
            mmin = max( mmin, dis);
        }
        cout << mmin << '\n';
    }
    return 0;
}