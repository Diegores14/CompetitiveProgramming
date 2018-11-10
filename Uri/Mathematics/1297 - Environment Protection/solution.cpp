#include <bits/stdc++.h>
using namespace std;
vector<double> p1(9), p2(9), q1(9), q2(9);
double w, d, a, k;
int N;

double f(double x, double limit){
	double num1=0, num2=0, den1=0, den2=0;
	for(int i=k; i>=0; i--){
	 	num1 = num1*x + p1[i];
		num2 = num2*x + p2[i];
		den1 = den1*x + q1[i];
		den2 = den2*x + q2[i];
	}
	double y1 = num1/den1;
	double y2 = num2/den2;
	if(limit > y1) return 0;
	if(limit > y2) return y1 - limit;
	return y1-y2;
}

double simpons_integration(double limit){
 	double h = w/N;
	double s = f(0, limit) + f(w, limit);
	for(int i = 1; i< N; ++i){
	 	double x = h*i;
		s += f(x, limit) * ((i&1)? 4 : 2);
	}
	s *= h/3;
	return s;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << fixed << setprecision(5);
	while(cin >> w >> d >> a >> k){
		for(int i=0; i<=k; i++)
			cin >> p1[i];
		for(int i=0; i<=k; i++)
			cin >> q1[i];
		for(int i=0; i<=k; i++)
			cin >> p2[i];
		for(int i=0; i<=k; i++)
			cin >> q2[i];
		double low=-d, hi = 0; 
		N = 1000*w;
		while(hi-low >= 1e-6){
		 	double mid = (hi+low)/2;
			double _a = simpons_integration(mid);
			//cout << _a << ' ' << mid << ' ' << ' ' << hi << ' ' << low << '\n';
			if(_a < a)
				hi = mid;
			else
				low = mid;
		}
		cout << -low << '\n';
	}
	return 0;
}