#include <bits/stdc++.h>
using namespace std;

vector<int> v(2000005, 0), sum(2000005, 0);

int phi(int n){
        int result = n;
	for(int i=2; i*i<=n; i++){
	 	if(n%i==0){ while(n%i == 0) n/=i;
			result -= result/i;
		}
	}
 	if(n>1)result-=result/n;
	return result;
}

int result(int n){
 	if(v[n]) return v[n];
	return   v[n] = result(phi(n))+1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b;   
	v[1]=v[2]=1;
	for(int i=2; i<=2000000; i++){  
			sum[i]=sum[i-1]+result(i);
	}
	cin >> n;   
	while(n--){      
		cin  >> a >> b;
		cout << sum[b]-sum[a-1] << '\n';
	}
 	return 0;
}