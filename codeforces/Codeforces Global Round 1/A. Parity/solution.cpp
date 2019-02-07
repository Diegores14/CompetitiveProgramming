#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int b, k;
    cin >> b >> k;
    int v[k];
    for(int &i : v) {
        cin >> i;
    }
    long long n = 0;
    long long pot = 1;
    for(int i=k-1; i>=0; i--){
        n += v[i] * pot;
        pot *= b;
    }
    if(n&1) {
        cout << "odd\n";
    } else {
        cout << "even\n";
    }
    return 0;
}