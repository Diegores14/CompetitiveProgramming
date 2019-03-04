#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector< queue<int> > v(n);
    for(int i=0; i<n; i++) {
        cin >> temp;
        v[temp].push(i);
    }
    int l = 1;
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        while(!v[i].empty()) {
            temp = n-i;
            while(!v[i].empty() && temp != 0) {
                int pos = v[i].front();
                ans[pos] = l;
                v[i].pop();
                temp--;
            }
            if(temp) {
                cout << "Impossible\n";
                return 0;
            }
            l++;
        }
    }
    cout << "Possible\n";
    for(int &i: ans) {
        cout << i << ' ';
    }
    return 0;
}