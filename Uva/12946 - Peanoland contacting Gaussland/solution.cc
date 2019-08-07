#include <bits/stdc++.h>
using namespace std;
int preComplex[4] = { 1, 1, -1, -1 };
int pre1[2] = { 1, -1 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p;
    int pascal[100][100];
    memset(pascal, 0, sizeof pascal);
    for(int i = 0; i < 100; i++) {
        pascal[i][0] = 1;
    }
    for(int i = 1; i < 100; i++) {
        for(int j = 1; j < 100; j++) {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }
    while(cin >> p) {
        long long ans[2] = {0, 0};
        for(int i = 0; i < 32; i++) {
            if( (p>>i)&1 ) {
                for(int j = 0; j <= i; j++) {
                    ans[(j&1)] += pascal[i][j]*pre1[(i-j)&1]*preComplex[j%4];
                }
            }
        }
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
    return 0;
}