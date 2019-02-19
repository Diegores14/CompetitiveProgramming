#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector< vector<int> > v(n, vector<int> (n,0));
    map<int,int> m;
    for(int i=0; i<n*n; i++) {
        cin >> temp;
        m[temp]++;
    }
    for(int i=0; i<(n>>1); i++) {
        for(int j=0; j<(n>>1); j++) {
            bool flag = false;
            for(auto &k: m) {
                if(k.second >=4) {
                    v[i][j] = k.first;
                    v[i][n-j-1] = k.first;
                    v[n-i-1][j] = k.first;
                    v[n-i-1][n-j-1] = k.first;
                    k.second -= 4;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    int mid = n>>1;
    if(n&1) {
        for(int i=0; i<mid; i++) {
            bool flag = false;
            for(auto &k: m) {
                if(k.second>=2) {
                    v[mid][i] = k.first;
                    v[mid][n-i-1] = k.first;
                    k.second -= 2;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout << "NO\n";
                return 0;
            }
        }
        for(int i=0; i<mid; i++) {
            bool flag = false;
            for(auto &k: m) {
                if(k.second>=2) {
                    v[i][mid] = k.first;
                    v[n-i-1][mid] = k.first;
                    k.second -= 2;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout << "NO\n";
                return 0;
            }
        }
        bool flag = false;
        for(auto &k: m) {
            if(k.second == 1) {
                v[mid][mid] = k.first;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << v[i][j] << ((j == n-1)? '\n' : ' ');
        }
    }
    return 0;
}