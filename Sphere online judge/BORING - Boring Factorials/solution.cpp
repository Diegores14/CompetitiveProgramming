#include <bits/stdc++.h>
using namespace std;
typedef __int128 ULL;
unsigned long long n, p;

string toString(__int128 num) {
    string str;
    do {
        int digit = num%10;
        str = to_string(digit) + str;
        num /= 10;
    } while(num != 0);
    return str;
}

ULL mul(ULL a, ULL b) {
    if(a <= 1) return a;
    if(a&1) return ( mul( (a-1) >> 1, b ) + b%p ) % p;
    else return ( ( mul((a)>>1, b) * (b * 2) % p ) % p) % p;
}

struct equation {
    ULL x, y, b;
    equation(ULL x, ULL y, ULL b): x(x), y(y), b(b) {}
    equation operator *(ULL k) {
        return equation(x * k, y * k, b * k);
    }
    equation operator -(equation other) {
        return equation(x - other.x, y - other.y, b - other.b);
    }
};

ULL extendedEuclides(ULL x, ULL y, ULL &a, ULL &b) {
    equation q1(1, 0, x);
    equation q2(0, 1, y);
    while(q2.b) {
        ULL k = q1.b / q2.b;
        equation temp = q1 - (q2 * k);
        q1 = q2;
        q2 = temp;
    }
    a = q1.x;
    b = q1.y;
    return q1.b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        if(n >= p) cout << "0\n";
        else {
            ULL y = 1;
            for(ULL i = n+1; i < p; i++) {
                y = (y * i) % p;
            }
            ULL inv, aux;
            extendedEuclides(y, p, inv, aux);
            cout  << toString((-1*inv + p)%p) << '\n';
        }
    }
    return 0;
}