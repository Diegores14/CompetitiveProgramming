#include <bits/stdc++.h>
using namespace std;

int calcular(vector<int> &v, int m){
	int k;
	if(m%v[v.size()-1]==0)return m/v[v.size()-1];
	vector<int> pd(1000002, 1000000);
	pd[0]=0;
	for(int i=0; i<(int)v.size(); i++){
		k=v[i];
		for(int j=k; j<=m; j++){
	        	pd[j]=min(pd[j],pd[j-k]+1);
		}
	}
	return pd[m];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b;
	cin >> n;
	while(n--){
	 	cin >> a >> b;  
		vector<int> v(a);
		for(int i=0; i<a; i++)cin >> v[i];
		sort(v.begin(),v.end());
		cout << calcular(v, b) << '\n';
	}
	return 0;
}