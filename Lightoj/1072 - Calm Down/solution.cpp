#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    long double R;
    int n;
    cout << fixed << setprecision(10);
    for(int k=1; k<=t; k++) {
        cin >> R >> n;
        long double theta = M_PI/n;
        cout << "Case " << k << ": " << (R*sin(theta))/(1+sin(theta)) << '\n';
    }
    return 0;
}