#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, aux, mmax=0;
    cin >> n >> k;
    map<int, int> m;
    for(int i=0; i<n; i++){
        cin >> aux;
        m[aux]++;
    }
    for(auto i: m){
        mmax = max(mmax, i.second%k);
    }
    cout << mmax << '\n';
    return 0;
}