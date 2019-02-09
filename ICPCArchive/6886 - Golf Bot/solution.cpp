#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd> & a,  bool invert) {
    int n = a.size();
    if (n == 1) 
        return;
    vector<cd> a0(n/2), a1(n/2);
    for(int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for(int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

int Solution(vector<int> &v, vector<int> & holes) {
    vector<cd> fa(v.begin(), v.end()), fb(v.begin(), v.end());
    int n = 1;
    while (n < fa.size() + fb.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fa[0] = 1;
    fft(fa, false);
    fft(fb, false);
    for(int i=0; i<n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<int> result(n);
    for(int i=0; i<n; i++) {
        result[i] = round(fa[i].real());
    }
    int ans = 0;
    for(int &i: holes) {
        if(result[i] > 0) {
            ans++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp;
    while(cin >> n) {
        vector<int> v(200001, 0);
        for(int i=0; i<n; i++) {
            cin >> temp;
            v[temp] = 1;
        }
        cin >> m;
        vector<int> holes(m);
        for(int &i: holes) {
            cin >> i;
        }
        cout << Solution(v, holes) << '\n';
    }
    return 0;
}