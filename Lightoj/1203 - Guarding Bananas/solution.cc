#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+5;
int n;
double eps = 1e-10;
const double PI = acos(-1);

struct point {
    long long x, y;
    point(){}
    point( long long x, long long y): x(x), y(y) {} 
    bool operator <( const point other ) const {
        return (x == other.x )? y < other.y : x < other.x;
    }
    point operator -( const point other ) const {
        return point( x - other.x, y - other.y );
    }
};

point v[tam];

long long cross( point a, point b ) {
    return a.x*b.y - b.x*a.y;
}

bool cw( point a, point b, point c ) {
    return cross( b-a, c-b ) < 0;
}

bool ccw( point a, point b, point c ) {
    return cross( b-a, c-b ) > 0;
}

double dist( point a ) {
    return sqrt( a.x*a.x + a.y*a.y );
}

double theta( point a, point b) {
    if(dist(a)*dist(b) == 0) return 0;
    return acos( (a.x*b.x+a.y*b.y)/(dist(a)*dist(b))  )*180/PI;
}

double solve() {
    if( n == 1 ) return 0;
    sort( v, v+n );
    point p1 = v[0], p2 = v[n-1];
    vector< point > a, b;
    a.push_back(p1);
    b.push_back(p1);
    for( int i = 1; i < n; i++ ) {
        if( i+1 == n || cw(p1, v[i], p2) ) {
            while( a.size() >= 2 && !cw( a[a.size()-2], a[a.size()-1], v[i] ) ) {
                a.pop_back();
            }
            a.push_back( v[i] );
        }
        if( i+1 == n || ccw(p1, v[i], p2) ) {
            while( b.size() >= 2 && !ccw( b[b.size()-2], b[b.size()-1], v[i] ) ) {
                b.pop_back();
            }
            b.push_back( v[i] );
        }
    }
    //cout << theta( a[a.size()-2] - p2, b[b.size()-2] - p2) << ' ' << theta( a[1] - p1, b[1] - p1) << '\n';
    double angle = min( theta( a[a.size()-2] - p2, b[b.size()-2] - p2), theta( a[1] - p1, b[1] - p1) );
    for( int i = 1; i < a.size()-1; i++ ) {
        angle = min( angle, theta( a[i-1] - a[i], a[i+1] - a[i]) );
        //cout << "a " << a[i+1].x << ' ' << a[i+1].y << ' ' << theta( a[i-1] - a[i], a[i+1] - a[i]) << '\n';
    }
    for( int i = 1; i < b.size()-1; i++ ) {
        angle = min( angle, theta( b[i-1] - b[i], b[i+1] - b[i]) );
        //cout << "b " << b[i-1].x << ' ' << b[i-1].y << ' ' << theta( b[i-1] - b[i], b[i+1] - b[i]) << '\n';
    }
    return angle;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n;
        for( int i = 0; i < n; i++ ) {
            cin >> v[i].x >> v[i].y;
        }
        cout << "Case " << cases << ": " << solve() << '\n';
    }
    return 0;
}