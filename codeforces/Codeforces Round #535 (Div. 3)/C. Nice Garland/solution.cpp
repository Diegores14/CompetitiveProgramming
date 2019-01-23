#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int temp, mmin = 1000000;
    vector<char> v({'B', 'G', 'R'});
    vector<char> ans;
    string s;
    int n;
    cin >> n;
    cin >> s;
    do {
        temp = 0;
        for(int i=0; i<n; i++) {
            if(s[i] != v[i%3]) {
                temp++;
            }
        }
        if(temp < mmin){
            mmin = temp;
            ans = v;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << mmin << '\n';
    for(int i=0; i<n; i++) {
        cout << ans[i%3];
    }
    cout << '\n';
    return 0;
}