typedef long double T;
typedef vector< vector<int> > vvi;
const T PI = acos(-1);

struct cd {
    T real, image;
    cd(T _real, T _image) {
        real = _real;
        image = _image;
    }
    cd(T _real) {
        real = _real;
        image = 0;
    }
    cd(){
        real = 0;
        image = 0;
    }
};

cd operator +(const cd &c1, const cd &c2) {
    return cd(c1.real + c2.real, c1.image + c2.image);
}

cd operator -(const cd &c1, const cd &c2) {
    return cd(c1.real - c2.real, c1.image - c2.image);
}

cd operator *(const cd &c1, const cd &c2) {
    return cd(c1.real * c2.real - c1.image * c2.image, c1.real * c2.image + c1.image * c2.real);
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for( int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if( i < j) {
            swap(a[i], a[j]);
        }
    }

    for( int len = 2; len <= n; len <<= 1) {
        T ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for( int i = 0; i<n; i += len) {
            cd w(1);
            for(int j=0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w * wlen;
            }
        }
    }

    if(invert) {
        for (cd & x: a) {
            x.real /= n;
            x.image /= n;
        }
    }
}