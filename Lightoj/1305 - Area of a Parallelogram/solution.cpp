#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long A[2], B[2], C[2], D[2];
    long long t;
    cin >> t;
    for( long long cases = 1; cases <= t; cases++) {
        cin >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1];
        D[0] = C[0] + A[0] - B[0];
        D[1] = C[1] + A[1] - B[1];
        long long Area = abs((A[0]*B[1] + B[0]*C[1] + C[0]*D[1] + D[0]*A[1]) - (A[1]*B[0] + B[1]*C[0] + C[1]*D[0] + D[1]*A[0]));
        Area >>= 1;
        cout << "Case " << cases << ": ";
        cout << D[0] << ' ' << D[1] << ' ' << Area << '\n';
    }
    return 0;
}