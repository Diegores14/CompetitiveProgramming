#include <bits/stdc++.h>
using namespace std;
int const tam = 300;
bool used[tam];
int x[tam];
int g, h, l;
int n;


long long areaRectangule(long long a, long long b) {
    return a*b;
}

long long areaTriangulo(long long a, long long b, long long c) {
    long double p = (long double)(a+b+c)/2;
    return sqrt( p*(p-a)*(p-b)*(p-c) );
}

int findRect() {
    for(int i = n-1; i > 0; i--) {
        if( !used[i] && !used[i-1] && x[i] == x[i-1] ) {
            for(int j = i-2; j > 0; j--) {
                if( !used[j] && !used[j-1] && x[j] == x[j-1] ) {
                    return areaRectangule(x[i], x[j]);
                }
            }
        }
    }
    return 0;
}

long long findTrian() {
    long long mmax = 0;
    for( int i = 0; i < n-2; i++ ) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                if(!used[i] && !used[j] && !used[k] && x[i] + x[j] > x[k]) {
                    mmax = max(mmax, areaTriangulo( x[i], x[j], x[k] ) );
                }
            }
        }
    }
    return mmax;
}

long long ans1() {
    for(int i = n-1; i > 0; i--) {
        if( !used[i] && !used[i-1] && x[i] == x[i-1] ) {
            used[i] = true;
            used[i-1] = true;
            for(int j = i-2; j > 0; j--) {
                if( !used[j] && !used[j-1] && x[j] == x[j-1] ) {
                    used[j] = true;
                    used[j-1] = true;
                    return areaRectangule(x[i], x[j]) + findTrian();
                }
            }
        }
    }
    return 0;
}

long long ans2() {
    long long mmax = 0;
    for( int i = 0; i < n-2; i++ ) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                if(!used[i] && !used[j] && !used[k] && x[i] + x[j] > x[k]) {
                    used[i] = true;
                    used[j] = true;
                    used[k] = true;
                    mmax = max(mmax, areaTriangulo( x[i], x[j], x[k] ) + findRect() );
                    used[i] = false;
                    used[j] = false;
                    used[k] = false;
                }
            }
        }
    }
    return mmax;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while( cin >> n ) {
        memset( used, 0, sizeof used );
        for( int i = 0; i < n; i++ ) {
            cin >> x[i];
        }
        sort(x, x+n);
        long long ans = 0;

        long long a, b;
        a = ans1();
        memset( used, 0, sizeof used );
        b = ans2();
        
        cout << max(a, b) << '\n';
    }
    return 0;
}