#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, cant1 = 0, cant2 = 0;
    cin >> n;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
        if(i>0) {
            cant1++;
        }
        if(i<0) {
            cant2++;
        }
    }
    if(n == 1 && v[0] == 0) {
        cout << "0\n";
        return 0;
    }
    if(cant1 >= ((n+1)>>1)) {
        cout << "1\n";
        return 0;
    }
    if(cant2 >= ((n+1)>>1)) {
        cout << "-1\n";
        return 0;
    }
    cout << "0\n";
    return 0;
}