#include <bits/stdc++.h>
using namespace std;
const int tam = 10000, tam1 = 1000000;
int hulam[tam];
bool criba[tam1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 2;
    hulam[0] = 1;
    hulam[1] = 2;
    memset(criba, -1, sizeof criba);
    criba[3] = 0; 
    int l = 3;
    while(n < tam) {
        if(criba[l]) {
            hulam[n] = l;
            for(int i = 0; i < n; i++) {
                criba[ l + hulam[i] ] = 0;
            }
            n++;
        }
        l++;
    }
    int t, x; 
    cin >> t;
    while(t--) {
        cin >> x;
        cout << hulam[x-1] << '\n';
    }
    return 0;
}