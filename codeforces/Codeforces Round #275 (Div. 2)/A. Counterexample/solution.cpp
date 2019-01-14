#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
    if(a == 0)
        return b;
    return GCD(b%a, a);
}

bool sol(long long a, long long b, long long c) {
    if(GCD(a,b) == 1 &&  GCD(b,c) == 1 && GCD(a,c) != 1) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long l, r;
    cin >> l >> r;
    for(long long a=l; a+2<=r; a++) {
        for(long long b = a+1; b+1<=r; b++) {
            for(long long c = b+1; c<=r; c++) {
                if(sol(a,b,c)) {
                    cout << a << ' ' << b << ' ' << c << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}