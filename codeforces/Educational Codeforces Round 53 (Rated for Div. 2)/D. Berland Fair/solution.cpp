#include <bits/stdc++.h>
using namespace std;




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, cont;
	long long t, ans=0, sum=1;
	cin >> n >> t;
	vector<int> v(n);
	vector<long long> prefix(n+1, 0);
	for(int i=0; i<n; i++){
	 	cin >> v[i];
		prefix[i+1] = prefix[i] + v[i];
	}
	long long aux;
	while(sum){
		sum = cont = 0;
		int l=0;
		for(int i=1; i<=n; i++){
		 	if(sum+prefix[i]-prefix[l] <= t){
			 	sum += v[i-1];
				cont++;
			}else{
				if(i-l==1){
				 	l=i;
				}else{
				 	l=--i;
				}
			}
		}
		if(sum){
			aux = (t/sum);
			ans += aux*cont;
			t = t - aux*sum;
		}
	}
	cout << ans << '\n';
	return 0;
}
