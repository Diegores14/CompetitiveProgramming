#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int cant1 = 0, cant2 = 0;
    long double p;
    cin >> s >> p;
    for(char &i: s) {
        if(i == '1') {
            cant1++;
        }
        if(i == '?') {
            cant2++;
        }
    }
    cout << fixed << setprecision(10) << (long double)cant1/s.size() + cant2 * p * ((long double)1/s.size()) << '\n';
    return 0;
}