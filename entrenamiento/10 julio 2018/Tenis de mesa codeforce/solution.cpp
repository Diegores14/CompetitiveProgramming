#include <bits/stdc++.h>
using namespace std; 


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, mx, cont = 1;
	long long k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	mx=max(v[0],v[1]);
	for(int i=2; i<n && cont<k; i++){if(mx<v[i]){cont=1;mx=v[i];}else cont++;}
	cout << mx << '\n';
 	return 0;
}