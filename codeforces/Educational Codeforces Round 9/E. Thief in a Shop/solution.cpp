#include <bits/stdc++.h>
using namespace std;
int Tam = 1<<20;
typedef long long LL;
const LL mod[2] = {2013265921, 7340033};
const LL root[2] = {440564289, 5};
const LL root_1[2] = {1713844692, 4404020};
const LL root_pw[2] = {(1<<27), (1<<20)};

LL extendedEuclidean(LL a, LL b, LL & x, LL & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = extendedEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// m is a number prime
LL inverse(LL a, LL m) {
    LL x, y;
    LL g = extendedEuclidean(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

void FFT(vector<LL> & a, bool invert, int idx) {
    int n = a.size();
    for(int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1)
            j ^=  bit;
        j ^= bit;
        if( i < j ) 
            swap(a[i], a[j]);
    }
    for( int len = 2; len <= n; len <<= 1) {
        LL wlen = invert? root_1[idx] : root[idx];
        for( int i = len; i < root_pw[idx]; i <<= 1)
            wlen = (wlen * wlen) % mod[idx];
        for(int i = 0; i < n; i += len) {
            LL w = 1;
            for(int j = 0; j < len/2; j++) {
                LL u = a[i+j], v = (a[i+j+len/2] * w) % mod[idx];
                a[i+j] = u + v < mod[idx] ? u + v : u + v - mod[idx];
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod[idx];
                w = (w * wlen) % mod[idx];
            }
        }
    }
    if(invert) {
        LL n_1 = inverse(n, mod[idx]);
        for(LL & x : a) 
            x = (x * n_1) % mod[idx];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, temp;
    cin >> n >> k;
    vector< vector<LL> > v(2, vector<LL>(Tam, 0));
    vector< vector<LL> > ans(2, vector<LL>(Tam, 0));
    ans[0][0] = 1;
    ans[1][0] = 1;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v[0][temp] = 1;
        v[1][temp] = 1;
    }
    FFT(v[0], false, 0);
    FFT(v[1], false, 1);
    FFT(ans[0], false, 0);
    FFT(ans[1], false, 1);
    while(k) {
        for(int i=0; i<2; i++) {
            if(k&1) {
                for(int j=0; j<Tam; j++) {
                    ans[i][j] = (ans[i][j] * v[i][j]) % mod[i];
                }
            }
            for(int j=0; j<Tam; j++) {
                v[i][j] = (v[i][j] * v[i][j]) % mod[i];
            }
        }
        k >>= 1;
    }
    FFT(ans[0], true, 0);
    FFT(ans[1], true, 1);
    bool flag = true;
    for(int i = 0; i <= 1000000; i++) {
        if(ans[0][i] > 0 || ans[1][i] > 0) {
            cout << (flag? "" : " ") << i;
            flag = false;
        }
    }
    cout << '\n';
    return 0;
}