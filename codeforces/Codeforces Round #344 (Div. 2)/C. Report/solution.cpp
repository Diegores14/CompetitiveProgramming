#include <bits/stdc++.h>
using namespace std;
typedef map<int, pair<int, int> >::reverse_iterator itera;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, t, r, mmax = 0;
    cin >> n >> k;
    int v[n];
    for(int &i: v) {
        cin >> i;
    }
    map<int, pair<int, int> > m;
    for(int i=0; i<k; i++) {
        cin >> t >> r;
        m[r] = make_pair(i, t);
        mmax = max(mmax, r);
    }
    // toma el rango más  grande de elementos
    vector<int> temp(mmax);
    for(int i=0; i<mmax; i++) {
        temp[i] = v[i];
    }
    // los ordeno
    sort(temp.begin(), temp.end());
    int l=0, order = 1, curr=-1;
    r = mmax;
    mmax--;
    // organizo los ragos dependiendo de su tamaño en el momento en que fueron realizados
    for(itera it = m.rbegin(); it != m.rend(); it++) {
        if(curr < it->second.first) {
            int aux = it->first;
            while(aux < r) {
                r--;
                if(order == 1){
                    v[r] = temp[mmax--];
                } else {
                    v[r] = temp[l++];
                }
            }
            curr = it->second.first;
            order = it->second.second;
        }
    }
    while(r) {
        r--;
        if(order == 1){
            v[r] = temp[mmax--];
        } else {
            v[r] = temp[l++];
        }
    }
    for(int i=0; i<n; i++) {
        cout << v[i] << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}