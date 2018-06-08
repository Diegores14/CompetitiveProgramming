#include <bits/stdc++.h>
using namespace std;

int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	double x, y;
	cin >> s >> x >> y;
	double aux = x + y*0.15;
	printf("TOTAL = R$ %.2lf\n", aux);
	return 0;
}