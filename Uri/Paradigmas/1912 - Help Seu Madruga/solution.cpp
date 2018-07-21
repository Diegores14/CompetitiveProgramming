#include <bits/stdc++.h>
using namespace std;

long double suma(vector<int> & v, double m){
	long double sum = 0;
	for(int i=0; i<(int)v.size(); i++){
	 	sum+= (v[i]-m>0)? v[i]-m : 0;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, sum, mx;
	cout << fixed << setprecision(4);
	while(cin >> a >> b, a || b){
	 	vector<int> v(a);
		mx=0; sum=0;
		for(int i=0; i<a; i++){cin >> v[i]; sum+=v[i]; mx= max(mx,v[i]);}
		if(b==sum){cout << ":D\n"; continue;}
		if(b>sum){cout << "-.-\n"; continue;}
		double izq = 0, der = mx;
		while(abs(izq-der)>=0.000001){
		 	if(suma(v, (der+izq)/2)<=b)der = (der+izq)/2;
		 	else izq = (der+izq)/2;
		}
		cout << der << '\n';
	}
 	return 0;
}