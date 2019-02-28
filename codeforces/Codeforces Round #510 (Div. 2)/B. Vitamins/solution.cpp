#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp; 
    string s;
    cin >> n;
    map<string, int> m;
    long long ans = 1e18;
    m["AB"] = 1e9;
    m["AC"] = 1e9;
    m["B"] = 1e9;
    m["BC"] = 1e9;
    m["C"] = 1e9;
    m["A"] = 1e9;
    m["ABC"] = 1e9;
    for(int i=0; i<n; i++){
        cin >> temp >> s;
        sort(s.begin(), s.end());
        m[s] = min(m[s], temp);
        for(char j: s) {
            string aux;
            aux.push_back(j);
            m[aux] = min(m[aux], temp); 
        }
    }
    ans = min(ans, (long long)m["A"] + m["B"] + m["C"]);
    ans = min(ans, (long long)m["AB"] + m["C"]);
    ans = min(ans, (long long)m["AC"] + m["B"]);
    ans = min(ans, (long long)m["A"] + m["BC"]);
    ans = min(ans, (long long)m["ABC"]);
    if(ans < 1e9)
        cout << ans << '\n';
    else {
        cout << -1 << '\n';
    }
    return 0;
}