#include <bits/stdc++.h>
using namespace std;
long double x[3], y[3], r[3], radio[3];
const long double eps = 1e-5;

long double delta(long double x1, long double y1, long double x2, long double y2){
    return x1 * y2 - y1 * x2;
}

long double quadratic(long double a, long double b, long double c, bool option){
    if(option){
        return (-b + sqrt(b*b - 4*a*c))/(2*a);
    }else{
        return (-b - sqrt(b*b - 4*a*c))/(2*a);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long double ansx, ansy;
    for(int i = 0; i<3; i++){
        cin >> x[i] >> y[i] >> radio[i];
        r[i] = radio[i] * radio[i];
    }
    long double C[2], Ca[2], Cb[2], R[2];
    C[0] = r[0] - r[1];
    C[1] = r[1] - r[2];
    Ca[0] = 2 * (r[1] * x[0] - r[0] * x[1]);
    Ca[1] = 2 * (r[2] * x[1] - r[1] * x[2]);
    Cb[0] = 2 * (r[1] * y[0] - r[0] * y[1]);
    Cb[1] = 2 * (r[2] * y[1] - r[1] * y[2]);
    R[0] = r[1] * (x[0] * x[0] + y[0] * y[0] + r[0] * r[0]) - r[0] * (x[1] * x[1] + y[1] * y[1] + r[1] * r[1]);
    R[1] = r[2] * (x[1] * x[1] + y[1] * y[1] + r[1] * r[1]) - r[1] * (x[2] * x[2] + y[2] * y[2] + r[2] * r[2]);
    if(abs(C[0]) < eps && abs(C[1]) < eps){
        // use cramer
        // cout << Ca[0] << ' ' << Cb[0] << ' ' << R[0] << '\n';
        // cout << Ca[1] << ' ' << Cb[1] << ' ' << R[1] << '\n';
        long double dx = delta(Ca[0], Cb[0], Ca[1], Cb[1]);
        ansx = delta(R[0], Cb[0], R[1], Cb[1]) / dx;
        ansy = delta(Ca[0], R[0], Ca[1], R[1]) / dx;
    }else{
        long double p, q, a, b, c;
        if(abs(C[0]) >= eps){
            p = (C[0]*Cb[1] - Cb[0]*C[1])/(C[0]*Ca[1] - Ca[0]*C[1]);
            q = (C[0]*R[1] - R[0]*C[1])/(C[0]*Ca[1] - Ca[0]*C[1]);
        }else{
            //cout << C[0] << ' ' << C[1] << ' ' <<  Ca[1] << '\n';
            p = (C[1]*Cb[0] - Cb[1]*C[0])/(C[1]*Ca[0] - Ca[1]*C[0]);
            q = (C[1]*R[0] - R[1]*C[0])/(C[1]*Ca[0] - Ca[1]*C[0]);            
        }
        if(p * p * C[0] + C[0]){
            a = p * p * C[0] + C[0];
            b = Cb[0] - p * q * 2 * C[0] - Ca[0] * p;
            c = q*q*C[0] + q*Ca[0] - R[0];
        }else{
            a = p * p * C[1] + C[1];
            b = Cb[1] - p * q * 2 * C[1] - Ca[1] * p;
            c = q*q*C[1] + q*Ca[1] - R[1];
        }
        //cout << a << '\n';
        long double x1 = quadratic(a, b, c, true);
        long double x2 = quadratic(a, b, c, false);
        long double y1 = q - p * x1;
        long double y2 = q - p * x2;
        long double theta1 = atan(radio[0]/sqrt((x[0]-x1)*(x[0]-x1) + (y[0]-y1)*(y[0]-y1)));
        long double theta2 = atan(radio[0]/sqrt((x[0]-x2)*(x[0]-x2) + (y[0]-y2)*(y[0]-y2)));
        if(theta1 >= theta2){
            ansx = x1;
            ansy = y1;
        }else{
            ansx = x2;
            ansy = y2;
        }
    }
    cout << fixed << setprecision(5) << ansx << ' ' << ansy << '\n';
    return 0;
}