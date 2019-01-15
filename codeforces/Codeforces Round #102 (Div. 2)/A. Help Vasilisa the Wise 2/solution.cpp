#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for(int x1=1; x1<10; x1++) {
        for(int x2=1; x2<10; x2++) {
            for(int x3=1; x3<10; x3++) {
                for(int x4=1; x4<10; x4++) {
                    if(x1!=x2 && x1!=x3 && x1!=x4 && x2!=x3 && x2!=x4 && x3!=x4) {
                        if(x1+x2==r1 && x3+x4==r2 && x1+x3==c1 && x2+x4==c2 && x1+x4==d1 && x2+x3==d2) {
                            cout << x1 << ' ' << x2 << '\n' << x3 << ' ' << x4 << '\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}