#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5 + 7;
int z[tam];
int n;

int bs(int longitud, int y) {
    int l = 0, r = 1e5+7;
    while(r-l != 1) {
        int mid = (l+r)>>1;
        int cant = 0;
        for(int i=longitud; i < y; i++) {
            cant += z[i] >= mid;
        }
        if(cant >= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void zFunction(string s) {
    int l = 0, r = 0;
    for(int i = 1; i < (int)s.size(); i++) {
        if(i <= r)
            z[i] = min(z[i-l], r-i+1);
        while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] - 1 > r) {
            l = i; r = i + z[i] - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cin >> n;
    memset(z, 0, sizeof z);
    zFunction(s2 + "'" + s1);    
    int ans = bs(s2.size(), s1.size() + s2.size() + 1);
    for(int i = 0; i < ans; i++) {
        cout << s2[i];
    }
    if(ans == 0) {
        cout << "IMPOSSIBLE";
    }
    cout << '\n';
    return 0;
}