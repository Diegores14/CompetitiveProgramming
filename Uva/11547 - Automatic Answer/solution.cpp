#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
	 	cin >> n;
		n*=567;
		n/=9;
		n+=7492;
		n*=235;
		n/=47;
		n-=498;
		n/=10;
		cout << ((n<0)? -1*(n%10) : (n%10)) << '\n';
	}
	return 0;
}