#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,y;
	double v[5]={4.00, 4.50,5.00,2.00,1.50};
	cin >> x >> y;
	cout << setprecision(2) << fixed << "Total: R$ " << v[x-1]*y << '\n';
	return 0;
}