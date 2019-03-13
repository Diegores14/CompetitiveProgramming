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