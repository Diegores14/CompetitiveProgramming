#include <bits/stdc++.h>
using namespace std;
typedef int atype;
struct ecuation {
    atype x, y, d;
    ecuation(atype x, atype y, atype d): x(x), y(y), d(d) {}
};

ecuation operator *(ecuation e, atype k) {
    e.x *= k; e.y *= k; e.d *= k;
    return e;
}

ecuation operator -(ecuation a, ecuation b) {
    a.x -= b.x; a.y -= b.y; a.d -= b.d;
    return a;
}

atype extended(atype mmax, atype mmin, atype & x, atype & y) {
    ecuation a1(1, 0, mmax), a2(0, 1, mmin);
    while(a2.d != 0) {
        atype k = a1.d/a2.d;
        ecuation temp = a1 - (a2*k);
        a1 = a2;
        a2 = temp;
    }
    x = a1.x;
    y = a1.y;
    return a1.d;
}