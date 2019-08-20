#include <bits/stdc++.h>
using namespace std;
int v[3][3];
const int tam = 3e5;

bool check(int x) {
    v[0][0] = x - v[0][1] - v[0][2];
    v[1][1] = x - v[1][0] - v[1][2];
    v[2][2] = x - v[2][1] - v[2][0];
    return v[0][0] > 0 && v[1][1] > 0 && v[2][2] > 0 && v[0][0] + v[1][1] + v[2][2] == x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for( int i = 0; i < 3; i++ ) {
        for(int &j: v[i] ) {
            cin >> j;
        }
    }
    for( int i = 3; i <= tam ; i++ ) {
        if( check(i) ) {
            for( int k = 0; k < 3; k++ ) {
                for(int j = 0; j < 3;  j++ ) {
                    cout << v[k][j] << ( (j+1==3)? '\n': ' ');
                }
            }
            return 0;
        }
    }
    return 0;
}