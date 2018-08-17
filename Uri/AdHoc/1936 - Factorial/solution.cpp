#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, ans=0;
	cin >> n;
	vector<int> v(n,-1);
	v[0]=1;
	int i;
	for(i=1; i<n; i++){ v[i] = i*v[i-1];if(v[i]>100000)break;} 
	while(n){
	 	if(v[i]<=n){ans++; n-=v[i];}
	 	else i--;
	}
	cout << ans << '\n';
 	return 0;
}