#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,k, ps, s, sum=0, mx=0, mx1;
	cin >> n >> k;
	ps=n%k;       
	s=(ps)? (n-ps)/(k-1) : n/k;
	ps+=(ps!=0)? ((n-ps)%(k-1)) : 0;
	vector<int> v(n);
	for(int i=0; i<n; i++){ cin >> v[i]; mx = (v[i]>v[mx])? i : mx;}
	for(int i=0; i<n; i+=s){
		mx=0;
		if(i<=mx && mx<i+ps){
			for(int j=0; j<ps; j++)mx1 = max(v[i+j],mx1);
			i += ps-s;
		}	
	 	else for(int j=0; j<s; j++)mx1 = max(v[i+j],mx1);
	 	sum+=mx1;
	}
	cout << sum << '\n';
	for(int i=0; i<n;i+=s)                     
		cout << ((i<=mx && mx<i+ps)? ps : s) << ((i==n-1)? '\n' : ' ');
	return 0;
}