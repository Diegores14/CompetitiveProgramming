#include <bits/stdc++.h>
using namespace std;
int tam = 1e5 + 5;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[tam], b[tam];
    bool ans[tam][4];
    memset(ans, 0, sizeof ans);
    for(int i=0; i<4; i++) {
        ans[n-1][i] = true;
    }
    for(int i=0; i<n-1; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n-1; i++) {
        cin >> b[i];
    }
    //cout << "hello\n";
    for(int i=n-2; i>=0; i--) {
        for( int j=0; j<4; j++ ) {
            for( int k=0; k<4; k++ ) {
                if(a[i] == (j|k) && b[i] == (j&k)) {
                    ans[i][j] |= ans[i+1][k];
                }
            }
        }
    }
    int answer = -1;
    for(int i=0; i<4; i++) {
        if(ans[0][i]) {
            answer = i;
            break;
        }
    }
    if(answer != -1) {
        cout << "YES\n";
        for(int i=0; i<n; i++) {
            cout << answer << ((i == n-1)? '\n' : ' ');
            for(int j=0; j<4; j++) {
                if(ans[i+1][j] && a[i] == (answer|j) && b[i] == (answer&j)) {
                    answer = j;
                    break;
                }
            }
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}