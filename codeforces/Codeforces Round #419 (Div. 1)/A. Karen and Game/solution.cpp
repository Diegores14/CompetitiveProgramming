#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > v;
vector<pair<int, int> > col, row; 
int n, m, total = 0;

void solcol() {
    for(int i=0; i<m; i++) {
        int mmin = 1e9;
        bool flag = true;
        for(int j=0; j<n; j++) {
            mmin = min(mmin, v[j][i]);
            if(v[j][i] == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            total += mmin;
            col.emplace_back(make_pair(i, mmin));
            for(int j=0; j<n; j++) {
                v[j][i] -= mmin;
            }
        }
    }
}

void solrow() {
    for(int i=0; i<n; i++) {
        int mmin = 1e9;
        bool flag = true;
        for(int j=0; j<m; j++) {
            mmin = min(mmin, v[i][j]);
            if(v[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            total += mmin;
            row.emplace_back(make_pair(i, mmin));
            for(int j=0; j<m; j++) {
                v[i][j] -= mmin;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    v.assign(n, vector<int> (m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    if(n<m) {
        solrow();
        solcol();
    } else {
        solcol();
        solrow();
    }
    bool flag = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j]) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        cout << total << '\n';
        for(auto &i: col) {
            while(i.second--) {
                cout << "col " << i.first+1 << '\n';
            }
        }
        for(auto &i: row) {
            while(i.second--) {
                cout << "row " << i.first+1 << '\n';
            }
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}