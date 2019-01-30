#include <bits/stdc++.h>
using namespace std;
int cont = 0, a = 0, total = 0;

void solution(string &s, int idx, int acom) {
    if(idx == s.size()) {
        cont++;
        if(acom == total) {
            a++;
        }
        return;
    }
    if(s[idx] != '?') {
        if(s[idx] == '+')
            solution(s, idx+1, acom+1);
        else
            solution(s, idx+1, acom-1);
    } else {
        solution(s, idx+1, acom+1);
        solution(s, idx+1, acom-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    for(char i: s1) {
        if(i == '+')
            total++;
        else
            total--;
    }
    solution(s2, 0, 0);
    cout << fixed << setprecision(11) << (long double) a/cont << '\n';
    return 0;
}