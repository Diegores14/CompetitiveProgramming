#include <bits/stdc++.h>
using namespace std;

int cantDiv(int n) {
    int cont = 1;
    for(int i=2; i*i<=n; i++) {
        int temp = 0;
        while(n%i==0) {
            n /= i;
            temp++;
        }
        cont *= (temp+1);
    }
    if(n>1) {
        cont *= 2;
    }
    return cont;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, temp, mmax=0;
    cin >> n;
    vector<int> v(100000, 0);
    for(int i=0; i<n; i++) {
        cin >> temp;
        v[temp]++;
        mmax = max(mmax, temp);
    }
    cout << mmax << ' ';
    for(int i=0; i<100000; i++) {
        if(v[i] && mmax%i == 0) {
            v[i]--;
        }
    }
    for(int i=mmax; i>=0; i--) {
        if(v[i]) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}