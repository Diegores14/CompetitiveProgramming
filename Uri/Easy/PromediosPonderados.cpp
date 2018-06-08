#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int N;
	double a, b, c;
	cin >> N;
	while(N--){
	 	cin >> a >> b >> c;
		cout << setprecision(1) << fixed << (a*2+b*3+c*5)/10 << '\n';
	}
	return 0;
}