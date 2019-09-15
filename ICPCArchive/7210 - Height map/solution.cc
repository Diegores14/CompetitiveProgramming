#include <bits/stdc++.h>
using namespace std;
int R, C;
const int tam = 101;
int v[tam][tam];
bool used[tam][tam];
 
void setUp(int i, int j, int x) {
    if( 0 <= i && i < R && 0 <= j && j < C && !used[i][j] && v[i][j] == x) {
        used[i][j] = true;
        setUp(i-1, j, x);
        setUp(i+1, j, x);
        setUp(i, j-1, x);
        setUp(i, j+1, x);
    }
}

int countBack() {
    int ans = 1;                                // One because is the face back.
    for( int i = 1; i < R; i++ ) {
        int firstBlock = 0;
        int secondBlock = 0;
        for( int j = 0; j < C; j++ ) {
            if( v[i-1][j] < v[i][j] ) {
                if( v[i][j] <= firstBlock || secondBlock <= v[i-1][j] ) {
                    ans++;
                }
                firstBlock = v[i-1][j];
                secondBlock = v[i][j];
            } else {
                firstBlock = 0;
                secondBlock = 0;
            }
        }
    }
    return ans;
}

int countFront() {
    int ans = 1;                                // One because is the face front.
    for( int i = R-2; i >= 0; i-- ) {
        int firstBlock = 0;
        int secondBlock = 0;
        for( int j = 0; j < C; j++ ) {
            if( v[i+1][j] < v[i][j] ) {
                if( v[i][j] <= firstBlock || secondBlock <= v[i+1][j] ) {
                    ans++;
                }
                firstBlock = v[i+1][j];
                secondBlock = v[i][j];
            } else {
                firstBlock = 0;
                secondBlock = 0;
            }
        }
    }
    return ans;
}

int countLeft() {
    int ans = 1;                                // One because is the face Left.
    for( int j = 1; j < C; j++ ) {
        int firstBlock = 0;
        int secondBlock = 0;
        for( int i = 0; i < R; i++ ) {
            if( v[i][j-1] < v[i][j] ) {
                if( v[i][j] <= firstBlock || secondBlock <= v[i][j-1] ) {
                    ans++;
                }
                firstBlock = v[i][j-1];
                secondBlock = v[i][j];
            } else {
                firstBlock = 0;
                secondBlock = 0;
            }
        }
    }
    return ans;
}

int countRight() {
    int ans = 1;                                // One because is the face Right.
    for( int j = C-2; j >= 0; j-- ) {
        int firstBlock = 0;
        int secondBlock = 0;
        for( int i = 0; i < R; i++ ) {
            if( v[i][j+1] < v[i][j] ) {
                if( v[i][j] <= firstBlock || secondBlock <= v[i][j+1] ) {
                    ans++;
                }
                firstBlock = v[i][j+1];
                secondBlock = v[i][j];
            } else {
                firstBlock = 0;
                secondBlock = 0;
            }
        }
    }
    return ans;
}

int countUp() {
    int ans = 0; 
    for( int i = 0; i < R; i++ ) {
        for( int j = 0; j < C; j++ ) {
            if( !used[i][j] ) {
                ans++;
                setUp( i, j, v[i][j] );
            }
        }
    }
    return ans; 
}


void solve() {
    for( int i = 0; i < R; i++ ) {
        for( int j = 0; j < C; j++ ) {
            cin >> v[i][j];
            used[i][j] = false;
        }
    }
    int ans = countUp() + 1;                    // plus one because face Down
    ans += countBack();
    ans += countFront();
    ans += countLeft();
    ans += countRight();
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while( cin >> R >> C ) {
        solve();
    }
    return 0;
}
