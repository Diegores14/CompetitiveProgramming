#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, r;
    cin >> n >> r;
    long double theta = M_PI/n;
    cout << fixed << setprecision(7) << (r*sin(theta))/(1-sin(theta)) << '\n';
    return 0;
}