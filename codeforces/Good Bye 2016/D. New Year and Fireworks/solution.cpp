#include <bits/stdc++.h>
using namespace std;
int dx[10] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[10] = {0, 1, 1, 1, 0, -1, -1, -1};
int TAM = 310;
int temp[400][400][10], ans[400][400], pos[400][400][10];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(ans, 0, sizeof ans);
    memset(pos, 0, sizeof pos);
    pos[TAM/2][TAM/2][0] = 1;
    int n, t;
    cin >> n;
    while(n--) {
        cin >> t;
        while(t--) {
            memset(temp, 0, sizeof temp);
            for(int i=0; i<TAM; i++) {
                for(int j=0; j<TAM; j++) {
                    for(int d=0; d<10; d++) {
                        if(pos[i][j][d]) {
                            temp[i + dx[d] ][j + dy[d] ][d] = 1;
                            ans[i + dx[d] ][j+dy[d] ] = 1;
                        }
                    }
                }
            }
            for(int i=0; i<TAM; i++) {
                for(int j=0; j<TAM; j++) {
                    for(int d=0; d<10; d++) {
                        pos[i][j][d] = temp[i][j][d];
                    }
                }
            }
        }
        memset(pos, 0, sizeof pos);
        for(int i=0; i<TAM; i++) {
            for(int j=0; j<TAM; j++) {
                for(int d=0; d<10; d++) {
                    if(temp[i][j][d]) {
                        pos[i][j][(d+1)%8] = 1;
                        pos[i][j][(d+7)%8] = 1;
                    }
                }
            }
        }
    }
    long long answer = 0;
    for(int i=0; i<TAM; i++) {
        for(int j=0; j<TAM; j++) {
            answer += ans[i][j];
        }
    }
    cout << answer << '\n';
    return 0;
}