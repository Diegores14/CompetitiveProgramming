// m is a number prime
LL inverse(LL a, LL m) {
    LL x, y;
    LL g = extendedEuclidean(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}