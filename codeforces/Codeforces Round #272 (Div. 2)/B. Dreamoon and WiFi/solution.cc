#include <bits/stdc++.h>
using namespace std;
int v[2] = {0, 0};
string s1, s2;
int n = 0;

long long solve(int idx, int sum) {
    if(idx == s2.size()) return sum == v[1];
    if(s2[idx] == '+') return solve(idx+1, sum+1);
    if(s2[idx] == '-') return solve(idx+1, sum);
    if(s2[idx] == '?') {
        return solve(idx+1, sum+1) + solve(idx+1, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s1 >> s2 ;
    for(char &i: s1) {
        v[i == '+']++;
    }
    for(char &i: s2) {
        n += i == '?';
    }
    cout << fixed << setprecision(15) << (long double)solve(0, 0) / (1LL<<n) << '\n';
    return 0;
}