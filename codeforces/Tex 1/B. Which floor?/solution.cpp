#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    n--;
    vector< pair<int, int> > v(m);
    set< int > ans;
    map<int,int> ma;
    for(auto &i: v) {
        cin >> i.first >> i.second;
        i.first--;
        i.second--;
        ma[i.first] = i.second;
    }
    for(int i=1; i<=100; i++) {
        int flag = true;
        for(auto &j: v) {
            if( j.first/i != j.second) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans.insert(n/i);
        }
    }
    if(ma.count(n)) {
        cout << ma[n]+1 << '\n';
        return 0;
    }
    if(ans.size() == 1) {
        cout << *ans.begin()+1 << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}