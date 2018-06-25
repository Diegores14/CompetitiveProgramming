#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;
	long double x;
	cin >> t;
	while(t--){
		cin >> x;
		long double res = log(x);
		//cout << setprecision(101) << fixed << res << '\n';
		cout << res << '\n';
		int i= log(int(res))+1;
		cout << (long long)res;
		for(; i<=101 && res-(long long)res>0; i++){res= res-(long long)res;res*=10; cout << int(res);}
		cout << '\n';
	}
 	return 0;
}