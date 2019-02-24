#include <bits/stdc++.h>
using namespace std;
int v[7][7];
char initial[7][7];
int p, k, n, m;
int region[7][7];
vector< vector<int> > used;

bool isGood(int i, int j) {
    if(i>0 && v[i][j] == v[i-1][j])
        return false;
    if(j>0 && v[i][j] == v[i][j-1])
        return false;
    if(i<n-1 && v[i][j] == v[i+1][j])
        return false;
    if(j<m-1 && v[i][j] == v[i][j+1])
        return false;
    if(i>0 && j>0 && v[i][j] == v[i-1][j-1])
        return false;
    if(i<n-1 && j>0 && v[i][j] == v[i+1][j-1])
        return false;
    if(i>0 && j<m-1 && v[i][j] == v[i-1][j+1])
        return false;
    if(i<n-1 && j<m-1 && v[i][j] == v[i+1][j+1])
        return false;
    return true;
}

bool solution(int x, int y) {
    cout << x << ' ' << y << '\n';
    if(x == n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << v[i][j] + 1 << ((j==m-1)? '\n' : ' ');
            }
        }
        return true;
    }
    bool ans;
    if(initial[x][y] == '-'){
        for(int i=0; i<used[region[x][y]].size(); i++) {
            if(used[region[x][y]][i]==0){
                used[region[x][y]][i]++;
                v[x][y] = i;
                if(isGood(x, y)){
                    if(y == m-1) {
                        ans = solution(x+1, 0);
                    } else {
                        ans = solution(x, y+1);
                    }
                    if(ans) {
                        return true;
                    }
                }
                used[region[x][y]][i]--;
            }
        }
    } else {
        if(used[region[x][y]][initial[x][y] - '1']) 
            return false;
        used[region[x][y]][initial[x][y] - '1']++;
        v[x][y] = initial[x][y] - '1';
        if(isGood(x, y)){
            if(y == m-1) {
                ans = solution(x+1, 0);
            } else {
                ans = solution(x, y+1);
            }
            if(ans) {
                return true;
            }
        }
        used[region[x][y]][initial[x][y] - '1']--;
    }
    v[x][y] == -1;
    return false;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> p;
    while(p--) {
        cin >> k >> n >> m;
        cout << k << '\n';
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> initial[i][j];
            }
        }
        string s;
        int limit, temp;
        cin >> limit;
        used.assign(limit, vector<int>());
        for(int i=0; i<limit; i++) {
            cin >> temp;
            used[i].assign(temp, 0);
            for(int j=0; j<temp; j++) {
                cin >> s;
                region[s[1]-'1'][s[3]-'1'] = i;
            }
        }
        memset(v, -1, sizeof v);
        cout << "Hello\n";
        solution(0,0);
    }
    return 0;
}