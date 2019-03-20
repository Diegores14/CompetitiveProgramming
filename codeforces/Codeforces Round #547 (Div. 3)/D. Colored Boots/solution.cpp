#include <bits/stdc++.h>
using namespace std;
queue<int> a[2][256];
int l[2][1500000];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int ans = 0;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++) {
        a[0][s1[i]].push(i+1);
        a[1][s2[i]].push(i+1);
    }
    for(int i = 'a'; i <= 'z'; i++) {
        while(!a[0][i].empty() && !a[1][i].empty()) {
            l[0][ans] = a[0][i].front();
            l[1][ans] = a[1][i].front();
            a[0][i].pop();
            a[1][i].pop();
            ans++;
        }
        while(!a[0][i].empty() && !a[1]['?'].empty()) {
            l[0][ans] = a[0][i].front();
            l[1][ans] = a[1]['?'].front();
            a[0][i].pop();
            a[1]['?'].pop();
            ans++;
        }
        while(!a[0]['?'].empty() && !a[1][i].empty()) {
            l[0][ans] = a[0]['?'].front();
            l[1][ans] = a[1][i].front();
            a[0]['?'].pop();
            a[1][i].pop();
            ans++;
        }
    }
    while(!a[0]['?'].empty() && !a[1]['?'].empty()) {
        l[0][ans] = a[0]['?'].front();
        l[1][ans] = a[1]['?'].front();
        a[0]['?'].pop();
        a[1]['?'].pop();
        ans++;
    }
    cout << ans << '\n';
    for(int i=0; i<ans; i++) {
        cout << l[0][i] << ' ' << l[1][i] << '\n';
    }
    return 0;
}