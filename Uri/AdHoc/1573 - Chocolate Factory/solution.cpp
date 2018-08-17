#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long a, b, c;
	while(cin >> a >> b >> c, a || b || c){
	 	cout << (int) pow(a*b*c, 1/3.0) << '\n';
	}
	return 0;
}