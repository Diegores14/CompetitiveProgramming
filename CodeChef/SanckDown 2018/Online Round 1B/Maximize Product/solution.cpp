#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, k;
	cin >> t;
	while(t--){
	 	cin >> n >> k;
		int mid = n/k, midk = (k>>1) + ((k&1)? 1 : 0);
		long long limitInf = mid-midk, limitSup = mid+midk;
		if(limitInf+1 <= 0 || limitSup >= n)
			cout << "-1\n";
		else{
		 	long long suma = ((limitSup*(limitSup+1))>>1) - ((limitInf*(limitInf+1))>>1);
			limitInf++;
			long long resultado = 1;
			if(suma>n){
				if(limitInf == 1){
					cout << "-1\n";
					continue;
				}
			 	while(suma>n){
			 	 	resultado = (resultado * ((limitInf-1)%mod * (limitInf-2)%mod)%mod)%mod;
					suma--;
					limitInf++;
				}
			}
			if(suma<n){
				if(limitSup==n-1){
				 	cout << "-1\n";
					continue;
				}
                                while(suma<n){
			 	 	resultado = (resultado * ((limitSup+1)%mod * (limitSup)%mod)%mod)%mod;
					suma++;
					limitSup--;
				}
			}
			while(limitInf<=limitSup){
			 	resultado = (resultado * (limitInf%mod * (limitInf-1)%mod)%mod)%mod;
				limitInf++;
			}
			cout << resultado << '\n';
		}
	}
	return 0;
}