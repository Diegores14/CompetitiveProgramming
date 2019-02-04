#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s) {
        int temp = 0, mmax = 0;
        int ansx = 1000000000, ansy = 1000000000;
        int x = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'B') {
                temp++;
            } else {
                temp--;
            }
            if(temp < 0) {
                x = i+1;
                temp = 0;
            }
            if(temp > mmax) {
                mmax = temp;
                ansx = x; 
                ansy = i;
            }
        }
        x = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'B') {
                temp--;
            } else {
                temp++;
            }
            if(temp < 0) {
                x = i+1;
                temp = 0;
            }
            if(temp > mmax || (temp == mmax && x < ansx)) {
                mmax = temp;
                ansx = x;
                ansy = i;
            }
        }
        cout << ansx+1 << ' ' << ansy+1 << '\n';
    }
    return 0;
}