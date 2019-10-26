#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
struct point {
    int x, y;
    point( int x = 0, int y = 0 ): x(x), y(y) {}
}; 

bool check( point p1, point p2, point p3 ) {
    long long x[3];
    x[0] = 1LL*(p1.x - p2.x)*(p1.x - p2.x) + 1LL*(p1.y - p2.y)*(p1.y - p2.y);
    x[1] = 1LL*(p3.x - p2.x)*(p3.x - p2.x) + 1LL*(p3.y - p2.y)*(p3.y - p2.y);
    x[2] = 1LL*(p3.x - p1.x)*(p3.x - p1.x) + 1LL*(p3.y - p1.y)*(p3.y - p1.y);
    sort( x, x+3 );
    return x[0]+x[1] == x[2] && x[0] && x[1] && x[2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    point p[3];
    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
    if( check(p[0], p[1], p[2] ) ) {
        cout << "RIGHT\n";
        return 0;
    }
    for( int i = 0; i < 3; i++ ) {
        for( int j = 0; j < 4; j++ ){
            p[i].x += dx[j];
            p[i].y += dy[j];
            if( check( p[0], p[1], p[2] ) ) {
                cout << "ALMOST\n";
                return 0;
            }
            p[i].x -= dx[j];
            p[i].y -= dy[j];
        }
    }
    cout << "NEITHER\n";
    return 0;
}