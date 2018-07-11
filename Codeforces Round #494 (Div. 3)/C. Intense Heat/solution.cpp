#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k, sum,aux;
	cin >> n >> k;
	double res=0;
	vector<int> v(n+1);
	v[0]=0;
	for(int i=1; i<=n; i++){cin >> aux; v[i]=aux+v[i-1];}
	for(int i=k; i<=n; i++){
		for(int j=0; j+i<=n; j++){
			sum=0;
		 	//for(int l=0; l<i; l++)sum+=v[j+l];
			res=max((double)(v[j+i]-v[j])/i,res);
		}
	}
	cout << fixed << setprecision(15) << res << '\n';
 	return 0;
}