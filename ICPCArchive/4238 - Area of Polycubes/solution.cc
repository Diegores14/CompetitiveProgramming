#include <bits/stdc++.h>
using namespace std;
const int tam = 205;
bool used[tam][tam][tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, p;
    char c;
    long long x, y, z;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        memset( used, 0, sizeof used );
        cin >> p;
        int v[p][3];
        for( int i = 0; i < p; i++ ) {
            cin >> v[i][0] >> c >> v[i][1] >> c >> v[i][2];
            v[i][0] += 100;
            v[i][1] += 100;
            v[i][2] += 100;
        }
        cout << cases << ' ';
        if( v[0][0] <= 0 || tam-1 <= v[0][0] || v[0][1] <= 0 || tam-1 <= v[0][1] || v[0][2] <= 0 || tam-1 <= v[0][2] ) {
            cout << "NO 1\n";
            continue;
        }
        used[v[0][0]][v[0][1]][v[0][2]] = true;
        bool ans = true;
        int sum = 0;
        for( int i = 1; i < p; i++ ) {
            if( v[i][0] <= 0 || tam-1 <= v[i][0] || v[i][1] <= 0 || tam-1 <= v[i][1] || v[i][2] <= 0 || tam-1 <= v[i][2] ) {
                //cout << "Hello1";
                cout << "NO " << i+1 << "\n";
                ans = false;
                break;
            }
            x = v[i][0];
            y = v[i][1];
            z = v[i][2];
            if( used[x][y][z] ) {
                //cout << "Hello2";
                cout << "NO " << i+1 << '\n';
                ans = false;
                break;
            }
            int temp = int(used[x+1][y][z]) + int(used[x-1][y][z]) + int(used[x][y+1][z]) + int(used[x][y-1][z]) + int(used[x][y][z+1]) + int(used[x][y][z-1]);
            //cout << "debug " << i+1 << ' ' << temp << '\n';
            //cout << x << ' ' << y << ' ' << z << '\n';
            if( temp != 0 ) {
                used[x][y][z] = true;
                sum += 2*temp;
            } else {
                //cout << "Hello3";
                cout << "NO " << i+1<< '\n';
                ans = false;
                break;
            }
        }
        if( ans ) {
            cout << p*6-sum << '\n';
        }
    }
    return 0;
}
