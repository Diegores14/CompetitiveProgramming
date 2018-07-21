#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	long long sum, res;
	while(cin >> n, n){
		vector<int> v(n);
		sum = 0; res = 0;
	 	for(int i=0; i<n; i++)cin >> v[i];
	 	for(int i=0; i<n-1; i++){
	 		sum += v[i];
	 		res += abs(sum);
	 	}
	 	cout << res << '\n';
	}                   
 	return 0;
}