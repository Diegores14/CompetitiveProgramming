#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double x;
	cout << setprecision(1) << fixed;
	for(int i = 0; i<100; i++){
	 	cin >> x;
		if(x<=10)cout << "A[" << i << "] = " << x << '\n';
	}
}