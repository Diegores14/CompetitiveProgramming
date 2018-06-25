#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,x;
	cin >> n;
	while(n--){
	 	cin >> x;
		if(x<64)cout << (((unsigned long long)1<<x)-1)/12000 << " kg\n";
		else cout << ULLONG_MAX/12000 << " kg\n";
	}
	return 0;
}