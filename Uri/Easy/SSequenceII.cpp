#include <bits/stdc++.h>
using namespace std;

int main(){
 	double s=0;
	int x=1;
	for(double i=1; i<=39; i+=2, x <<=1)s+=i/x;
	cout << setprecision(2) << fixed << s << '\n';
}