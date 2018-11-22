#include <bits/stdc++.h>
using namespace std;

struct point{
	long double x, y;
	point(){};
	point(long double x_, long double y_): x(x_), y(y_){}
} a[3];

long double PI = 3.14159265359;
long double  eps = 1e-3;

bool check(int n,const long double & rx, const long double & ry){
	long double theta = 2*PI/n;
	int ans = 0;
	long double x = a[0].x;
	long double y = a[0].y;
	for(int i=1; i<n; i++){
		long double _x = x;
		x = (_x - rx) * cos(theta) - (y - ry) * sin(theta) + rx;
		y = (y - ry) * cos(theta) + (_x - rx) * sin(theta) + ry;
	 	if((abs(x - a[1].x) <= eps && abs(y - a[1].y) <= eps) || (abs(x - a[2].x) <= eps && abs(y - a[2].y) <= eps))
	 		ans++;
	}
	return ans == 2;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long double ans = 0;
	for(int i=0; i<3; i++)
		cin >> a[i].x >> a[i].y;
	long double A = a[0].x*a[0].x + a[0].y * a[0].y;	
	long double B = a[1].x*a[1].x + a[1].y * a[1].y;
	long double C = a[2].x*a[2].x + a[2].y * a[2].y;
	long double D  = a[0].x * (a[1].y - a[2].y) - a[1].x * (a[0].y - a[2].y) + a[2].x * (a[0].y - a[1].y);
	long double rx = (A * (a[1].y - a[2].y) - B * (a[0].y - a[2].y) + C * ( a[0].y - a[1].y))/(2.0*D);
	long double ry = (a[0].x * (B - C) - a[1].x * ( A - C) + a[2].x * (A - B))/(2.0*D);
	long double rr = sqrt((a[0].x - rx) * (a[0].x - rx) + (a[0].y - ry) * (a[0].y - ry));
	for(int i = 3; i<=100; i++){
		if(check(i, rx, ry)){
			long double theta = PI/i;
			ans = i * rr * sin(theta) * rr * cos(theta);
			break;
		}
	}
	cout << fixed << setprecision(8) << ans << '\n';
	return 0;
}