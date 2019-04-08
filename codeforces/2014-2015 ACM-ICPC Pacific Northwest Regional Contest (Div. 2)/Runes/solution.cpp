#include <bits/stdc++.h>
using namespace std;

int fill(string s, char val) {
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '?') {
            s[i] = val;
        }
    }
    return stoi(s);
}

string find(string s, int &idx) {
    bool flag = false;
    string ans;
    for(; idx < s.size(); idx++) {
        if(flag && (s[idx] == '+' || s[idx] == '-' || s[idx] == '*' || s[idx] == '=' )) {
            break;
        } else {
            flag = true;
            ans.push_back(s[idx]);
        }
    }
    return ans;
}

long long operation(int num1, char op, int num2) {
    long long ans = 0;
    if(op == '+') {
        ans = num1 + num2;
    }
    if(op == '-') {
        ans = num1 - num2;
    }
    if(op == '*') {
        ans = 1LL*num1 * num2;
    }
    return ans;
}

void eraseNumbers(set<char> &numbers, string &s) {
    if(s.size() > 1 && ((s[0] == '-' && s[1] == '?') || s[0] == '?')) {
        numbers.erase('0');
    }
    for(char &i: s) {
        numbers.erase(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        set<char> numbers({'0','1','2','3','4','5','6','7','8','9'});
        char op;
        string num1, num2, ans;
        int idx = 0;
        num1 = find(s, idx);
        eraseNumbers(numbers, num1);
        op = s[idx++];
        num2 = find(s, idx);
        eraseNumbers(numbers, num2);
        idx++;
        ans = find(s, idx);
        eraseNumbers(numbers, ans);
        bool flag = true;
        for(char i: numbers) {
            if(operation(fill(num1, i), op, fill(num2, i)) == fill(ans, i)) {
                cout << i << '\n';
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "-1\n";
        }
    }
    return 0;
}