#include <bits/stdc++.h>
using namespace std;


bool check( const string &s1, const string &s2 ) {
    return s1.size() > s2.size() || s1 > s2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    while( cin >> n >> s ) {
        string temp = s;
        int j = (temp.size()-1)>>1;
        for( int i = 0; i <= j; i++ ) {
            temp[i] = s[i];
            temp[temp.size()-i-1] = s[i];
        }
        while( n ) {
            if( check(temp, s) ) {
                cout << temp << '\n';
                n--;
            }
            while( temp[j] == '9' && 0 <= j ) {
                temp[j] = '0';
                temp[temp.size() - j - 1] = '0';
                j--;
            }
            //cout << "debug " << temp << '\n';
            if(j == -1) {
                temp.push_back('1');
                j++;
            }
            temp[j]++;
            temp[temp.size() - j - 1] = temp[j];
            j = ((int)temp.size() - 1)/2;
        }
    }
    return 0;
}