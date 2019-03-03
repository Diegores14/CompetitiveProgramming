#include <bits/stdc++.h>
using namespace std;
int n;
vector< vector<int> > v;

int bs(int pos, int row, int val) {
    int r = n+1;
    while(r-pos != 1) {
        int mid = (pos+r)>>1;
        if(v[row][mid] < val) {
            pos = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    n = s.size();
    v.assign(26, vector<int> (s.size()+1, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<26; j++) {
            v[j][i+1] = v[j][i];
        }
        v[s[i]-'a'][i+1]++;
    }
    long long ans = 0;
    for(int i=0; i<n; i++) {
        int l = i;
        for(char j: t) {
            l = bs(l, j-'a', v[j-'a'][l]+1);
            if(l > n) {
                break;
            }
        }
        if(l <= n) {
            ans += n-l+1;
        }
    }
    cout << ans << '\n';
    return 0;
}