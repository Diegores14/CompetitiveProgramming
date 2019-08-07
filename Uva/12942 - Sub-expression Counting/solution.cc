#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6;
int lps[tam];

int solve(string &s1, string &s2) {
    int j = 0, i = 0, ans = 0;
    while( i < s1.size() ) {
        if( s1[i] == s2[j] ) {
            i++;
            j++;
        }
        if( j == s2.size() ) {
            ans++;
            j = lps[j-1];
        } else {
            if ( i < s1.size() && s1[i] != s2[j] ) {
                if ( j != 0 ) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    }
    return ans;
}

void buildLPS(const string &s) {
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while( i < s.size() ) {
        if( s[i] == s[len] ) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if ( len != 0 ) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

string trans(string &s) {
    string temp = "";
    bool flag = true;
    for(char &i: s) {
        if('0' <= i && i <= '9') {
            if(flag)
                temp.push_back('0');
            flag = false;
            continue;
        }
        flag = true;
        if('a' <= i && i <= 'z') {
            temp.push_back('0');
            continue;
        }
        if('+' == i || '-' == i || '/' == i || '*' == i) {
            temp.push_back('+');
            continue;
        }
        temp.push_back(i);
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    while( cin >> s1 >> s2 ) {
        string temp = "";
        bool flag = true;
        s1 = trans(s1);
        s2 = trans(s2);
        buildLPS(s1);
        cout << solve(s2, s1) << '\n';
    }
    return 0;
}