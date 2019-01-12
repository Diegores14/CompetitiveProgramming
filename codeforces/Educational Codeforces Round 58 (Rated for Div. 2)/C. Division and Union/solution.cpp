#include <bits/stdc++.h>
using namespace std;
struct node {
    int x;
    char type;
    node(int _x, char T){x=_x; type = T;}
    bool operator <(node other) const {
        if( x == other.x){
            if(type == 'l'){
                return true;
            }else {
                return false;
            }
        }else
            return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, mmin = 1e9, mmax = 0, l, r;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans[1000002];
        vector<node> s;
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++) {
            cin >> l >> r;
            v[i].first = l;
            v[i].second = r;
            s.push_back(node(l, 'l'));
            s.push_back(node(r, 'r'));
        }
        int sum = 0, temp = 1;
        sort(s.begin(), s.end());
        for(node &i: s) {
            sum += ((i.type=='l')? 1 : -1);
            ans[i.x] = temp;
            if(sum == 0){
                temp++;
            }
        }
        if(temp > 2){
            for(int i=0; i<n; i++) {
                if(ans[v[i].first] == 1) {
                    cout << "1";
                }else{
                    cout << "2";
                }
                cout << ((i == n-1)? '\n' : ' '); 
            }
        }else {
            cout << "-1\n";
        }
    }
    return 0;
}