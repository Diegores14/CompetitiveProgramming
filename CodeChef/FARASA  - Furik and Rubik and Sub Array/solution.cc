#include <bits/stdc++.h>
using namespace std;
const int tam = 2e6+1;
const int tam1 = 2e7+1;
long long v[tam];
bool used[tam1];
long long a[tam];
int n, len = 0;
// TODO PARA LA FFT
typedef double T;
struct cpx {
    T real, image;
    cpx( T real, T image ): real(real), image(image) {}
    cpx( T real ): real(real), image(0) {}
    cpx() { real = 0; image = 0; }
};

cpx operator +( const cpx &c1, const cpx &c2) {
    return cpx(c1.real + c2.real, c1.image + c2.image );
}
cpx operator -( const cpx &c1, const cpx &c2) {
    return cpx(c1.real - c2.real, c1.image - c2.image );
}
cpx operator *( const cpx &c1, const cpx &c2) {
    return cpx(c1.real*c2.real - c1.image*c2.image, c1.image*c2.real + c1.real*c2.image);
}
const double PI = acos(-1);

void fft( vector<cpx> & a, bool invert ) {
    int n = a.size();
    for( int i = 1, j = 0; i < n; i++ ) {
        int bit = (n>>1);
        for(; j & bit; bit >>= 1 ) 
            j ^= bit;
        j ^= bit;
        if ( i < j ) 
            swap( a[i], a[j] );
    }
    for( int len = 2; len <= n; len <<= 1 ) {
        double ang = 2*PI / len * (invert? -1 : 1 );
        cpx wlen(cos(ang), sin(ang));
        for( int i = 0; i < n; i += len ) {
            cpx w(1);
            for( int j = 0; j < len/2; j++ ) {
                cpx u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w*wlen;
            }
        }
    }
    if( invert ) {
        for( cpx &x : a ) {
            x.real /= n;
            x.image /= n;
        }
    }
}

// END FFT

void solve1() {
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    for( int i = 0; i < n; i++ ) {
        long long sum = 0;
        for( int j = i; j < n; j++ ) {
            sum += a[j];
            v[len++] = sum;
        }
    }
    sort( v, v + len );
    long long ans = 0; 
    for( int i = 1; i < len; i++ ) {
        if( v[i-1] != v[i] ) {
            ans++;
        }
    } 
    cout << ans << '\n';
}

void solve2() {
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    for( int i = 0; i < n; i++ ) {
        long long sum = 0;
        for( int j = i; j < n; j++ ) {
            sum += a[j];
            used[ sum ] = true;
        }
    }
    long long ans = 0;
    for( int i = 0; i < tam1; i++) {
        ans += used[i];
    }
    cout << ans - 1 << '\n';
}

void solve3( ) {
    int temp, sum = 0, len = 1;
    vector< cpx > a1(tam), a2(tam);
    while (len < tam + tam ) 
        len <<= 1;
    int mid = len/4;
    a1.resize(len);
    a2.resize(len);
    a1[mid].real = 1;
    a2[mid].real = 1;
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        sum += temp;
        a1[mid+sum].real = 1;
        a2[mid-sum].real = 1;
    }
    fft(a1, false);
    fft(a2, false);
    for( int i = 0; i < len; i++ ) {
        a1[i] = a1[i]*a2[i];
    }
    fft(a1, true);
    int ans = 0;
    for( int i = mid*2+1; i < len; i++ ) {
        temp = round( a1[i].real );
        //cout << temp << ' ';
        if( temp ) ans++;
    }
    cout << ans - 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    if( n <= 2000 ) {
        solve1();
    } else {
        if( n <= 20000 ) {
            solve2();
        } else {
            solve3();
        }
    }
    return 0;
}