#include <bits/stdc++.h>
using namespace std;
int x, y;
long long Mx, My;
int rock[666][2];

bool ischeck() {
    Mx=0; My=0;
    for(int i=0; i<666; i++) {
        if(abs(rock[i][0] - x) == 1){
            x = rock[i][0];
            return true;
        }
        if(abs(rock[i][1]-y) == 1){
            y = rock[i][1];
            return true;
        }
    }
    return false;
}

int main() {
    for(int i=0; i<666; i++) {
        cin >> rock[i][0] >> rock[i][1];
        Mx += rock[i][0];
        My += rock[i][1];
    }
    int k = 2, xk = 2, yk = 2;
    for(int i=0; (k!=-1 && xk!=-1 && yk!=-1) && (k!=0 && xk!=0 && yk!=0) && i<2000; i++){
        if(ischeck()) {
            cout << x << ' '  << y << '\n';
        } else {
            int tempx = (Mx/666 - x);
            int tempy = (My/666 - y);
            x += tempx/abs(tempx);
            y += tempy/abs(tempy);
            cout << x << ' ' <<  y << '\n';
        }
        cout.flush();
        cin >> k >> xk >> yk;
        k--;
        Mx -= rock[k][0];
        rock[k][0] = xk;
        Mx += xk;
        My -= rock[k][1];
        rock[k][1] = yk;
        My += yk;
    }
    return 0;
}