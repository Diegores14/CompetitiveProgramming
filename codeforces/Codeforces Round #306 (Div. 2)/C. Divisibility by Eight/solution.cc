#include<bits/stdc++.h>
using namespace std;
const int tam = 105;
int dp[tam][10];
string s;
string answer;

int solve(int idx, int res, int cantidad) {
    if(idx == s.size() && cantidad == 0) return false;
    int &ans = dp[idx][res];
    if(ans != -1) return ans;
    ans = 0;
    ans |= solve(idx+1, (res*10 + s[idx] - '0')%8, cantidad );
    if(ans) {
        answer = s[idx] + answer;
    } else {
        ans |= solve(idx+1, res, cantidad-1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> s;
    for(int i = 1; i < 10; i++) {
        dp[s.size()][i] = 0;
    }
    dp[s.size()][0] = 1;
    int ans = solve(0, 0, s.size());
    if( ans ) {
        cout << "YES\n";
        bool flag = false;
        for(int i = 0; i < answer.size(); i++) {
            if(answer[i] != '0') flag = true;
            if(flag)
                cout << answer[i];
        } 
        if(flag == false) {
            cout << '0';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}