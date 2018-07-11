#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int v[3];
	double a1, a2, a3, r1, r2, p;
	cout << fixed << setprecision(4);
	while(cin >> v[0] >> v[1] >> v[2]){
		sort(v, v+3);
		p=(double)(v[0]+v[1]+v[2])/2;
		a1=sqrt(p*(p-v[0])*(p-v[1])*(p-v[2]));
		r1=(v[0]*v[1]*v[2])/(a1*4);
		r2=a1/p;
		a2=r1*r1*3.1415926535897;
		a3=r2*r2*3.1415926535897;
		cout << a2-a1 << ' ' << a1-a3 << ' ' << a3 << '\n';
	}
	return 0;
}