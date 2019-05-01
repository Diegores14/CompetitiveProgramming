#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long o[2], a[2], b[2];
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    //cout << acos() << '\n';
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ": ";
        cin >> o[0] >> o[1] >> a[0] >> a[1] >> b[0] >> b[1];
        a[0] -= o[0];
        a[1] -= o[1];
        b[0] -= o[0];
        b[1] -= o[1];
        long double radio = sqrt(a[0]*a[0] + a[1]*a[1]);
        long double temp = (a[0]*b[0] + a[1]*b[1]) / (radio * radio);
        if(temp > 1) {
            temp = 1;
        }
        if(temp < -1) {
            temp = -1;
        }
        long double theta = acos( temp );
        cout << theta * radio << '\n';
    }
    return 0;
}