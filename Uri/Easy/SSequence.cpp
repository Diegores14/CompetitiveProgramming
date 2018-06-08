#include <bits/stdc++.h>
using namespace std;

int main(){
	double x=1,s=0;
	for(; x<=100;x++)s+=1/x;
	cout << setprecision(2) << fixed << s << '\n';
	return 0;
}	