#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for(char &i: s) {
        v[i-'a']++;
    }
    int ans = v['i'-'a'];
    ans = min(ans, v['t'-'a']);
    int temp = 0;
    if(v['n'-'a']/3) {
        temp = 1;
        v['n'-'a'] -= 3;
        temp += v['n'-'a']/2;
    }
    ans = min(ans, temp);
    ans = min(ans, v['e'-'a']/3);
    cout << ans << '\n';
    return 0;
}