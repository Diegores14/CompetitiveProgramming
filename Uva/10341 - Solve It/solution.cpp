#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-9;

int p, q, r, s, t, u;

long double f(long double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(4);
    while(cin >> p >> q >> r >> s >> t >> u){
        long double a = 0, b = 1.00000001;
        while(b-a > eps){
            long double mid = (b+a)/2;
            long double temp = f(mid);
            if(temp <= eps){
                b = mid;
            }else{
                a = mid;
            }
        }
        if(a > 1 || ( a == 0 && abs(f(b)) > 1e-6 ))
            cout << "No solution\n";
        else
            cout << b << '\n';
    }
    return 0;
}